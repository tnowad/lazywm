#include "plugin_manager.h"
#include <iostream>

void PluginManager::LoadPlugin(const std::string &plugin_name) {
  std::cout << "Loading plugin: " << plugin_name << std::endl;
  // Simulate plugin loading
}

void PluginManager::UnloadPlugin(const std::string &plugin_name) {
  std::cout << "Unloading plugin: " << plugin_name << std::endl;
  // Simulate plugin unloading
}

void PluginManager::ExecutePlugins() {
  std::cout << "Executing plugins..." << std::endl;
  for (const auto &plugin : plugins_) {
    plugin->Execute();
  }
}
