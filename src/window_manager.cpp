#include "window_manager.h"
#include <iostream>

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
      ipc_manager_(std::make_unique<IPCManager>()) {}

void WindowManager::Initialize() {
  std::cout << "Initializing WindowManager..." << std::endl;
}

void WindowManager::StartEventLoop() {
  std::cout << "Starting event loop..." << std::endl;
  // Simulate event loop
}
