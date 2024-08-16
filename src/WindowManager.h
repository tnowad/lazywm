#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <X11/Xlib.h>
#include <memory>
#include <vector>

class WindowManager {
public:
  static WindowManager &getInstance();
  void run();

private:
  WindowManager();
  ~WindowManager();

  void handleEvent(XEvent *event);

  Display *display;
  int screen;
  Window root;
  Cursor cursor;
};

#endif // WINDOWMANAGER_H
