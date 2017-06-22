/*******************************************************************************
 * Copyright (C) 2009-2011 FuseSource Corp.
 * 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "notifier.h"
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/eventfd.h>
#include <errno.h>
#include <string.h>


static inline void die(const char *msg)
{
	fprintf(stderr, "error: %s: %s(%d)\n", msg, strerror(errno), errno);
	exit(EXIT_FAILURE);
}

static inline void usage(void)
{
	fprintf(stderr, "usage: oom_eventfd_test <cgroup.event_control> <memory.oom_control>\n");
	exit(EXIT_FAILURE);
}

#define BUFSIZE 256

int oom_event_listener(char *event_ctrl,char *oom_ctrl){
        char buf[BUFSIZE];
        int efd, cfd, ofd, rb, wb;
        uint64_t u;


        if ((efd = eventfd(0, 0)) == -1)
            die("eventfd");

        if ((cfd = open(event_ctrl, O_WRONLY)) == -1)
            die("cgroup.event_control");

        if ((ofd = open(oom_ctrl, O_RDONLY)) == -1)
            die("memory.oom_control");

        if ((wb = snprintf(buf, BUFSIZE, "%d %d", efd, ofd)) >= BUFSIZE)
            die("buffer too small");

        if (write(cfd, buf, wb) == -1)
            die("write cgroup.event_control");

        if (close(cfd) == -1)
            die("close cgroup.event_control");

        for (;;) {

            if (read(efd, &u, sizeof(uint64_t)) != sizeof(uint64_t))
                die("read eventfd");

            if (access(event_ctrl,0)==-1){
                printf("group not exists\n");
                return 2;
            }

            printf("mem_cgroup oom event received\n");
            return 1;
        }

        return 0;
}
