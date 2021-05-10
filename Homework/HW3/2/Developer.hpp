#pragma once

#include <string>
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;

class Developer{
 public:
  Developer(const std::string& name = "");
  std::string getName() const;
  double getSalary() const;
  TeamLead* getTeamLead() const;

  void setInitialSalary(double amount);
  void increaseSalary(double amount);
  void setTeamLead(TeamLead* teamlead);

  void sendLeavingRequest();
  void sendPromotionRequest(double amount);

 protected:
  std::string name;
  double salary;
  TeamLead* teamlead;
};