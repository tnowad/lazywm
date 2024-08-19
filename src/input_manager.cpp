#include "input_manager.h"

#include <iostream>
#include <thread>
#include <utility>

InputManager::InputManager() { this->commands_ = {}; }

void InputManager::BindCommand(KeyCode key_code, unsigned int modifiers,
                               std::function<void()> command) {
  commands_[{key_code, modifiers}] = std::move(command);
}

void InputManager::HandleInput(const XEvent& event) {
  if (event.type == KeyPress) {
    KeyCode key_code = event.xkey.keycode;
    unsigned int modifiers = event.xkey.state;

    auto it = commands_.find({key_code, modifiers});
    if (it != commands_.end()) {
      std::thread([it]() { it->second(); }).detach();
    } else {
      std::cerr << "No command bound for key code: " << key_code
                << " with modifiers: " << modifiers << std::endl;
    }
  }
}
