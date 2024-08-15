#include <X11/X.h>
#include <X11/Xlib.h>
#include <cstdio>

int main() {
  Display *display = XOpenDisplay(NULL);
  Window root;

  root = DefaultRootWindow(display);

  XSelectInput(display, root, KeyPressMask);

  XEvent event;
  while (true) {
    XNextEvent(display, &event);

    if (event.type == KeyPress) {
      printf("Keycode: %u\n", event.xkey.keycode);
      break;
    }
  }

  XCloseDisplay(display);
  return 0;
}
