#include "monitor_manager.h"
#include <iostream>

void MonitorManager::AddMonitor() {
  std::cout << "Adding monitor..." << std::endl;
}

void MonitorManager::RemoveMonitor() {
  std::cout << "Removing monitor..." << std::endl;
}

void MonitorManager::ConfigureMonitor(int index) {
  std::cout << "Configuring monitor " << index << std::endl;
}
