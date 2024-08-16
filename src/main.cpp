#include "WindowManager.h"

int main() {
  WindowManager& wm = WindowManager::getInstance();
  wm.run();
  return 0;
}
