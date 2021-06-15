//
// Created by User on 15.6.2021 г..
//

#include "stream.hpp"

#include <iostream>

Stream::Stream(const std::string &source) : MultiMediaFile("",0,""), source(source) {
}

void Stream::print_debug_state() {
    std::cout << name << '.' << extension << " | " << sizeMB << " MB ----> " << source << "\n";
}

MultiMediaFile *Stream::clone() {
    return new Stream(*this);
}
