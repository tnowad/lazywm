
#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <string>

class LogManager {
 public:
  void LogError(const std::string &message);
  void LogInfo(const std::string &message);
};

#endif  // LOG_MANAGER_H
