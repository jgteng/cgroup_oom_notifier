/*******************************************************************************
 * Copyright (C) 2009-2011 FuseSource Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
package ji;

import org.fusesource.hawtjni.runtime.JniArg;
import org.fusesource.hawtjni.runtime.JniClass;
import org.fusesource.hawtjni.runtime.JniMethod;
import org.fusesource.hawtjni.runtime.Library;

/**
 * Created by ji on 17-5-18.
 */
@JniClass
public class OomNotifierNative {

    private static final Library LIBRARY = new Library("native-oom-notifier", OomNotifierNative.class);

    static {
        LIBRARY.load();
    }


    @JniMethod(cast = "char *")
    public static final native long oom_event_listener(@JniArg(cast = "char *") String ptr, @JniArg(cast = "char *") String ptr2);

}
