//
// Created by User on 15.6.2021 г..
//

#include "videoFile.hpp"
#include <iostream>

VideoFile::VideoFile(const std::string &name, size_t sizeMB, const std::string &extension, const std::string &subs)
        : MultiMediaFile(name, sizeMB, extension), subs(subs) {
}

void VideoFile::print_debug_state() {
    std::cout << name << '.' << extension << " | " << sizeMB << " MB ----> " << subs << "\n";
    for (size_t i = 0; i < audios.size(); ++i) {
        std::cout << i+1 << ". ";
        audios[i].print_debug_state();
    }
}

MultiMediaFile *VideoFile::clone() {
    return new VideoFile(*this);
}
