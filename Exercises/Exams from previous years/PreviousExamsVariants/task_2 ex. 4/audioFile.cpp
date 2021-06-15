//
// Created by User on 15.6.2021 г..
//

#include "audioFile.hpp"
#include <iostream>

AudioFile::AudioFile(const std::string &name, size_t sizeMB, const std::string &extension,
                     const std::string &singerName, size_t length) : MultiMediaFile(name, sizeMB, extension),
                                                                     singerName(singerName), length(length) {
}

void AudioFile::print_debug_state() {
    std::cout << name << '.' << extension << " | " << sizeMB << " MB ----> " << singerName << " - " << length
              << "min.\n";
}

MultiMediaFile *AudioFile::clone() {
    return new AudioFile(*this);
}
