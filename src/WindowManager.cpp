#include "WindowManager.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <iostream>

WindowManager::WindowManager() {
  display = XOpenDisplay(nullptr);
  if (!display) {
    std::cerr << "Unable to open X display" << std::endl;
    exit(1);
  }
  screen = DefaultScreen(display);
  root = RootWindow(display, screen);
  cursor = XCreateFontCursor(display, XC_left_ptr);

  XDefineCursor(display, root, cursor);
  XSelectInput(display, root,
               SubstructureNotifyMask | FocusChangeMask | KeyPressMask |
                   ButtonPressMask | ButtonReleaseMask | PointerMotionMask);
}

WindowManager::~WindowManager() { XCloseDisplay(display); }

WindowManager &WindowManager::getInstance() {
  static WindowManager instance;
  return instance;
}

void WindowManager::run() {
  XEvent event;
  while (true) {
    XNextEvent(display, &event);
    handleEvent(&event);
  }
}

void WindowManager::handleEvent(XEvent *event) {
  std::cout << "Received event: " << event->type << std::endl;
}
