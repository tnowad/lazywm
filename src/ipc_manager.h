#ifndef IPC_MANAGER_H
#define IPC_MANAGER_H

#include <string>

class IPCManager {
public:
  void SendMessage(const std::string &message);
  void ReceiveMessage();
};

#endif // IPC_MANAGER_H
