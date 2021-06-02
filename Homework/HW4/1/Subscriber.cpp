#include "Subscriber.hpp"

Subscriber::Subscriber(std::string id) : id(id) {}

void Subscriber::signal(Message message) {
  messages.push_back(message);
}