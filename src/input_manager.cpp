#include "input_manager.h"

void InputManager::BindCommand(int key_code, std::function<void()> command) {
  commands_[key_code] = std::move(command);
}

void InputManager::HandleInput(int key_code) {
  auto it = commands_.find(key_code);
  if (it != commands_.end()) {
    it->second();
  }
}
