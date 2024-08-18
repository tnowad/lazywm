#include "window_layout_manager.h"

#include <iostream>

void TilingLayout::ArrangeWindows(const std::vector<int> &windows) {
  std::cout << "Arranging windows in tiling layout." << std::endl;
}

void FloatingLayout::ArrangeWindows(const std::vector<int> &windows) {
  std::cout << "Arranging windows in floating layout." << std::endl;
}

void WindowLayoutManager::SetLayoutStrategy(
    std::unique_ptr<LayoutStrategy> strategy) {
  layout_strategy_ = std::move(strategy);
}

void WindowLayoutManager::ArrangeWindows(const std::vector<int> &windows) {
  if (layout_strategy_) {
    layout_strategy_->ArrangeWindows(windows);
  }
}
