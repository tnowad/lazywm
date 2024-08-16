#include "WindowManager.h"
#include <iostream>

WindowManager::WindowManager() {
  display = XOpenDisplay(nullptr);
  if (!display) {
    std::cerr << "Unable to open X display" << std::endl;
    exit(1);
  }
  screen = DefaultScreen(display);
  root = RootWindow(display, screen);
  XSelectInput(display, root, SubstructureNotifyMask | FocusChangeMask);
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
  switch (event->type) {
  case MapRequest:
    break;
  case DestroyNotify:
    break;
  }
}
