#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <memory>
#include <string>
#include <vector>

class Plugin {
 public:
  virtual void Initialize() = 0;
  virtual void Execute() = 0;
  virtual ~Plugin() = default;
};

class PluginManager {
 public:
  void LoadPlugin(const std::string &plugin_name);
  void UnloadPlugin(const std::string &plugin_name);
  void ExecutePlugins();

 private:
  std::vector<std::unique_ptr<Plugin>> plugins_;
};

#endif  // PLUGIN_MANAGER_H
