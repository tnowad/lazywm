#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <functional>
#include <unordered_map>

class InputManager {
public:
  void BindCommand(int key_code, std::function<void()> command);
  void HandleInput(int key_code);

private:
  std::unordered_map<int, std::function<void()>> commands_;
};

#endif // INPUT_MANAGER_H
