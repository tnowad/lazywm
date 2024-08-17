#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>

class ConfigManager {
public:
  static ConfigManager &GetInstance();
  void LoadConfig(const std::string &filename);

private:
  ConfigManager();
  ConfigManager(const ConfigManager &) = delete;
  ConfigManager &operator=(const ConfigManager &) = delete;
};

#endif // CONFIG_MANAGER_H
