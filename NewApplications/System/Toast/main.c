#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xcomposite.h>

#include <stdio.h>

int main(int argc, char **argv)
{
  Display *dpy;
  XVisualInfo vinfo;
  int depth;
  XVisualInfo *visual_list;
  XVisualInfo visual_template;
  int nxvisuals;
  int i;
  XSetWindowAttributes attrs;
  Window parent;
  Visual *visual;

  dpy = XOpenDisplay(NULL);

  nxvisuals = 0;
  visual_template.screen = DefaultScreen(dpy);
  visual_list = XGetVisualInfo (dpy, VisualScreenMask, &visual_template, &nxvisuals);

  for (i = 0; i < nxvisuals; ++i)
    {
      printf("  %3d: visual 0x%lx class %d (%s) depth %d\n",
             i,
             visual_list[i].visualid,
             visual_list[i].class,
             visual_list[i].class == TrueColor ? "TrueColor" : "unknown",
             visual_list[i].depth);
    }

  if (!XMatchVisualInfo(dpy, XDefaultScreen(dpy), 32, TrueColor, &vinfo))
    {
      fprintf(stderr, "no such visual\n");
      return 1;
    }

  printf("Matched visual 0x%lx class %d (%s) depth %d\n",
         vinfo.visualid,
         vinfo.class,
         vinfo.class == TrueColor ? "TrueColor" : "unknown",
         vinfo.depth);

  parent = XDefaultRootWindow(dpy);

  XSync(dpy, True);

  printf("creating RGBA child\n");

  visual = vinfo.visual;
  depth = vinfo.depth;

  attrs.colormap = XCreateColormap(dpy, XDefaultRootWindow(dpy), visual, AllocNone);
  attrs.background_pixel = 0;
  attrs.border_pixel = 0;

  XCreateWindow(dpy, parent, 10, 10, 150, 100, 0, depth, InputOutput,
                visual, CWBackPixel | CWColormap | CWBorderPixel, &attrs);

  XSync(dpy, True);

  printf("No error\n");

  return 0;
}
