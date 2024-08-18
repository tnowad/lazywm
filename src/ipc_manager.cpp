#include "ipc_manager.h"

#include <iostream>

void IPCManager::SendMessage(const std::string &message) {
  std::cout << "Sending message: " << message << std::endl;
}

void IPCManager::ReceiveMessage() {
  std::cout << "Receiving message..." << std::endl;
}
