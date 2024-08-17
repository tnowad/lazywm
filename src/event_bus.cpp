#include "event_bus.h"

void EventBus::Subscribe(EventHandler handler) { handlers_.push_back(handler); }

void EventBus::Publish(int event) {
  for (const auto &handler : handlers_) {
    handler(event);
  }
}
