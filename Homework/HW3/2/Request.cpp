#include "Request.hpp"

Request::Request(const std::string& message, const std::string& sender)
    : message(message), sender(sender) {
  requestsCreated++;//when new Request is created add 1 to the counter
  ID = requestsCreated;
}

std::string Request::getMessage() const {
  return message;
}
std::string Request::getSender() const {
  return sender;
}
int Request::getCount() const {
  return requestsCreated;
}
int Request::getID() const {
  return ID;
}

int Request::requestsCreated = 0;//initializing static int to be 0 here