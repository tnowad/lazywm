
#ifndef EVENT_BUS_H
#define EVENT_BUS_H

#include <functional>
#include <vector>

class EventBus {
public:
  using EventHandler = std::function<void(int)>;

  void Subscribe(EventHandler handler);
  void Publish(int event);

private:
  std::vector<EventHandler> handlers_;
};

#endif // EVENT_BUS_H
