//
// Created by User on 21.5.2021 г..
//

#ifndef HW4_PRAC_DESKTOPPC_HPP
#define HW4_PRAC_DESKTOPPC_HPP

#include "computer.hpp"


class DesktopPC : public Computer {
public:
    DesktopPC(int power = 0,unsigned int size = 0,double frequency = 0.0,int price = 0);
    void print() override;
private:
    int power;
};


#endif //HW4_PRAC_DESKTOPPC_HPP
