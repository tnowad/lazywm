#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <X11/X.h>
#include <X11/Xlib.h>

#include <functional>
#include <unordered_map>

namespace std {
template <>
struct hash<std::pair<KeyCode, unsigned int>> {
  size_t operator()(const std::pair<KeyCode, unsigned int>& pair) const {
    size_t hash1 = std::hash<KeyCode>{}(pair.first);
    size_t hash2 = std::hash<unsigned int>{}(pair.second);
    return hash1 ^ (hash2 << 1);
  }
};
}  // namespace std

class InputManager {
 public:
  InputManager();
  void BindCommand(KeyCode key_code, unsigned int modifiers,
                   std::function<void()> command);
  void HandleInput(const XEvent& event);

 private:
  std::unordered_map<std::pair<KeyCode, unsigned int>, std::function<void()>>
      commands_;
};

#endif  // INPUT_MANAGER_H
