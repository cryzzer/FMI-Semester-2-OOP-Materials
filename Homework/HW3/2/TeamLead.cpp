#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary)
    : Developer(name) {
  setInitialSalary(salary);
  teamlead = this;//pointing that the leader of the team is this object
}

std::vector<Developer*> TeamLead::getTeam() {
  return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
  developer->setInitialSalary(salary);
  // when adding new Developer to the team, change the pointer of teamLead to this object
  developer->setTeamLead(this);
  team.push_back(developer);
}
void TeamLead::removeDeveloperFromTeam(const std::string& name) {
  // checking if the vector is empty
  if (!team.empty()) {
    // if the name exists we take its position and turn the flag to true that
    // there is a Developer with this name
    size_t index = -1;
    bool nameExists = false;
    // start form the end, because if there are multiple developers with this
    // name, we remove the last one that has been added
    for (size_t i = team.size() - 1; i >= 0; i--) {
      if (team[i]->getName() == name) {
        // setting the teamLead to nullptr, since he no longer has a "boss"
        team[i]->setTeamLead(nullptr);
        index = i;
        nameExists = true;
        break;
      }
    }

    if (nameExists) {
      // creating a temporay vector that will represent the remaining developers
      // of the team
      std::vector<Developer*> temp;
      for (size_t i = 0; i < team.size(); i++) {
        // copying each of the developers, except the leaving one
        if (i == index) {
          continue;
        }
        temp.push_back(team[i]);
      }
      // returning all the data to the original vector "team"
      team = temp;
    }
  }
}

void TeamLead::increaseTeamSalariesBy(double amount) {
  // checking if the vector is empty
  if (!team.empty()) {
    // for each member of team, increase their salaries by "amount"
    for (auto& x : team) {
      x->increaseSalary(amount);
    }
  }
}
void TeamLead::decreaseTeamSalariesBy(double amount) {
  // calling the increase function, but add '-' to make the amount negative and
  // decrease their salaries
  increaseTeamSalariesBy(-amount);
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
  leavingRequests.push_back(leavingRequest);
}
void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
  promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
  // checking if the vector is empty
  if (!leavingRequests.empty()) {
    // for each developer that wanted to leave, remove him from the team, by
    // getting his name and calling the remove function
    for (const auto& leaver : leavingRequests) {
      removeDeveloperFromTeam(leaver.getSender());
    }
    // at the end clear the vector that holds all LeavingRequests
    leavingRequests.clear();
  }
}
void TeamLead::fulfillPromotionRequests() {
  // checking if the vector is empty
  if (!promotionRequests.empty()) {
    for (const auto& promotion : promotionRequests) {
      for (auto& person : team) {
        // for each promotionRequest and each member of the team, if their names
        // match, increase the salary of this member by the amount wanted
        if (promotion.getSender() == person->getName()) {
          person->increaseSalary(promotion.getAmount());
        }
      }
    }
    // at the end clear the vector that holds all PromotionRequests
    promotionRequests.clear();
  }
}