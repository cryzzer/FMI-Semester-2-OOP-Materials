#include <iostream>

#include "Request.hpp"
#include "LeavingRequest.hpp"
#include "Developer.hpp"
#include "TeamLead.hpp"

int main() {
    Developer d1("John");
    TeamLead t1("Boss", 2000);
    t1.addDeveloperToTeam(&d1, 1500);
    t1.increaseTeamSalariesBy(100);
    for(Developer *dev : t1.getTeam()){
        std::cout << dev->getName() << ", " << dev->getSalary() << std::endl;
    }
    d1.sendLeavingRequest();
    t1.fulfillLeavingRequests();
    std::cout << "After leaving:" << std::endl;
    for(Developer *dev : t1.getTeam()){
        std::cout << dev->getName() << ", " << dev->getSalary() << std::endl;
    }

}