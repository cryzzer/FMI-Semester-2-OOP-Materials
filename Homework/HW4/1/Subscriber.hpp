#pragma once
#include <string>
#include <vector>

#include "Message.hpp"

class Subscriber {
 public:
  std::string id;

  Subscriber(std::string id);

  virtual ~Subscriber() = default;

  virtual void signal(Message message);

  virtual int read() const = 0;

 protected:
  std::vector<Message> messages;
};