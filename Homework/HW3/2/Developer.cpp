#include "Developer.hpp"
#include "TeamLead.hpp"


Developer::Developer(const std::string& name) : name(name), salary(0), teamlead(nullptr){
}

std::string Developer::getName() const {
  return name;
}
double Developer::getSalary() const {
  return salary;
}
TeamLead* Developer::getTeamLead() const {
  return teamlead;
}

void Developer::setInitialSalary(double amount) {
  if (salary == 0) {
    salary = amount;
  }
}

void Developer::increaseSalary(double amount) {
  salary += amount;
}

void Developer::setTeamLead(TeamLead* teamlead) {
  this->teamlead = teamlead; 
}

//if teamlead is a valid pointer, store the Request in vector
void Developer::sendLeavingRequest() {
  if (teamlead != nullptr) {
    teamlead->addLeavingRequest(LeavingRequest(name));
  }
}
//if teamlead is a valid pointer, store the Request in vector
void Developer::sendPromotionRequest(double amount) {
  if (teamlead != nullptr) {
    teamlead->addPromotionRequest(PromotionRequest(name, amount));
  }
}
