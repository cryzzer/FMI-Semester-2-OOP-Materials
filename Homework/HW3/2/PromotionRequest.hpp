#pragma once

#include "Request.hpp"

class PromotionRequest : public Request {
 public:
  PromotionRequest(const std::string& sender = "", double amount = 0);
  double getAmount() const;

 private:
  double amount;
};