#include <X11/X.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <stdio.h>
#include "vroot.h"

int main() {
    Display *dpy = XOpenDisplay(getenv("DISPLAY"));

    Window root = DefaultRootWindow(dpy);

    GC g = XCreateGC(dpy, root, 0, NULL);

    XWindowAttributes wa;
    XGetWindowAttributes(dpy, root, &wa);

    unsigned int screen_num = DefaultScreen(dpy);

    unsigned int width = DisplayWidth(dpy, screen_num);
    unsigned int height = DisplayHeight(dpy, screen_num);

    XSetForeground(dpy, g, XWhitePixelOfScreen(DefaultScreenOfDisplay(dpy)));

    while(1) {
        XFillRectangle(dpy, root, g, random()%width, random()%height, 100, 100);

        if(random()%500 < 1) {
            XClearWindow(dpy, root);
        }

        XFlush(dpy);
        usleep(1000*500);
    }
}
