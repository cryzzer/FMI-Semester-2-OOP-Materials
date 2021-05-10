#pragma once

#include <string>

class Request {
 public:
  Request(const std::string& message = "", const std::string& sender = "");
  std::string getMessage() const;
  std::string getSender() const;
  int getCount() const;
  int getID() const;

 private:
  std::string message;
  std::string sender;
  //using static int so when we create new Request, this int keeps its value and does not reset
  static int requestsCreated;
  int ID;
};