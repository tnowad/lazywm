#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <X11/Xlib.h>

#include <memory>
#include <vector>

#include "compositor.h"
#include "config_manager.h"
#include "event_bus.h"
#include "input_manager.h"
#include "ipc_manager.h"
#include "log_manager.h"
#include "monitor_manager.h"
#include "plugin_manager.h"
#include "session_manager.h"
#include "state_store.h"
#include "window_layout_manager.h"
#include "workspace_manager.h"

class WindowManager {
 public:
  WindowManager();
  ~WindowManager();
  void Initialize();
  void StartEventLoop();

 private:
  std::unique_ptr<EventBus> event_bus_;
  std::unique_ptr<ConfigManager> config_manager_;
  std::unique_ptr<InputManager> input_manager_;
  std::unique_ptr<WindowLayoutManager> window_layout_manager_;
  std::unique_ptr<WorkspaceManager> workspace_manager_;
  std::unique_ptr<Compositor> compositor_;
  std::unique_ptr<SessionManager> session_manager_;
  std::unique_ptr<PluginManager> plugin_manager_;
  std::unique_ptr<MonitorManager> monitor_manager_;
  std::unique_ptr<LogManager> log_manager_;
  std::unique_ptr<StateStore> state_store_;
  std::unique_ptr<IPCManager> ipc_manager_;
  Display *display_;
  Window root_window_;
  Cursor cursor_;
};

#endif  // WINDOW_MANAGER_H
