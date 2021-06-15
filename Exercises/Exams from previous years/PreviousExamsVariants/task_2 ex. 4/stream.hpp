//
// Created by User on 15.6.2021 г..
//

#ifndef VERSION_1_STREAM_HPP
#define VERSION_1_STREAM_HPP

#include "multiMediaFile.hpp"

class Stream : public MultiMediaFile {
public:
    Stream(const std::string& source = "");
    void print_debug_state() override;

    MultiMediaFile *clone() override;
private:
    std::string source;
};


#endif //VERSION_1_STREAM_HPP
