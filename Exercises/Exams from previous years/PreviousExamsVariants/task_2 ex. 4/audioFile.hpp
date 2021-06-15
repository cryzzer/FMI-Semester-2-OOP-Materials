//
// Created by User on 15.6.2021 г..
//

#ifndef VERSION_1_AUDIOFILE_HPP
#define VERSION_1_AUDIOFILE_HPP

#include "multiMediaFile.hpp"


class AudioFile : public MultiMediaFile {
public:
    AudioFile(const std::string &name = "", size_t sizeMB = 0, const std::string &extension = "",
              const std::string &singerName = "", size_t length = 0);

    void print_debug_state() override;

    MultiMediaFile *clone() override;

private:
    std::string singerName;
    size_t length;
};


#endif //VERSION_1_AUDIOFILE_HPP
