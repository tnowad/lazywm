#include "window_manager.h"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>

WindowManager::WindowManager()
    : event_bus_(std::make_unique<EventBus>()),
      config_manager_(std::make_unique<ConfigManager>()),
      input_manager_(std::make_unique<InputManager>()),
      window_layout_manager_(std::make_unique<WindowLayoutManager>()),
      workspace_manager_(std::make_unique<WorkspaceManager>()),
      compositor_(std::make_unique<Compositor>()),
      session_manager_(std::make_unique<SessionManager>()),
      plugin_manager_(std::make_unique<PluginManager>()),
      monitor_manager_(std::make_unique<MonitorManager>()),
      log_manager_(std::make_unique<LogManager>()),
      state_store_(std::make_unique<StateStore>()),
      ipc_manager_(std::make_unique<IPCManager>()),
      display_(XOpenDisplay(nullptr)),
      root_window_(DefaultRootWindow(display_)),
      cursor_(XCreateFontCursor(display_, XC_left_ptr)) {}

WindowManager::~WindowManager() { XCloseDisplay(display_); }

void WindowManager::Initialize() {
  if (!display_) {
    this->log_manager_->LogError("Failed to open X display.");
    return;
  }

  XSelectInput(display_, root_window_,
               SubstructureNotifyMask | SubstructureRedirectMask |
                   KeyPressMask | KeyReleaseMask | ButtonPressMask |
                   ButtonReleaseMask | PointerMotionMask | FocusChangeMask |
                   VisibilityChangeMask | EnterWindowMask | LeaveWindowMask);

  XDefineCursor(display_, root_window_, cursor_);
}

void WindowManager::StartEventLoop() {
  if (!display_) {
    this->log_manager_->LogError("Failed to open X display.");
    return;
  }

  XEvent event;
  while (true) {
    XNextEvent(display_, &event);
    switch (event.type) {
      default:
        this->log_manager_->LogInfo("Unknown event: " +
                                    std::to_string(event.type));
        break;
    }
  }
}
