/*******************************************************************************
 * Copyright (C) 2009-2011 FuseSource Corp.
 * 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef INCLUDED_FOO_H
#define INCLUDED_FOO_H

#include <stdlib.h>
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

struct foo {
   int    a;
   size_t b;     
   char   c[20];        
   struct foo *prev;            	
};

typedef struct _point {
   int    x;
   int    y;
} point;



int oom_event_listener(char *event_ctrl,char *oom_ctrl);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* INCLUDED_FOO_H */
