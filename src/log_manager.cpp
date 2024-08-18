#include "log_manager.h"

#include <iostream>

void LogManager::LogError(const std::string &message) {
  std::cerr << "Error: " << message << std::endl;
}

void LogManager::LogInfo(const std::string &message) {
  std::cout << "Info: " << message << std::endl;
}
