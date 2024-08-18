
#ifndef WINDOW_LAYOUT_MANAGER_H
#define WINDOW_LAYOUT_MANAGER_H

#include <memory>
#include <vector>

class LayoutStrategy {
 public:
  virtual void ArrangeWindows(const std::vector<int> &windows) = 0;
  virtual ~LayoutStrategy() = default;
};

class TilingLayout : public LayoutStrategy {
 public:
  void ArrangeWindows(const std::vector<int> &windows) override;
};

class FloatingLayout : public LayoutStrategy {
 public:
  void ArrangeWindows(const std::vector<int> &windows) override;
};

class WindowLayoutManager {
 public:
  void SetLayoutStrategy(std::unique_ptr<LayoutStrategy> strategy);
  void ArrangeWindows(const std::vector<int> &windows);

 private:
  std::unique_ptr<LayoutStrategy> layout_strategy_;
};

#endif  // WINDOW_LAYOUT_MANAGER_H
