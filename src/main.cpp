#include "window_manager.h"

int main() {
  WindowManager wm;
  wm.Initialize();
  wm.StartEventLoop();
  return 0;
}
