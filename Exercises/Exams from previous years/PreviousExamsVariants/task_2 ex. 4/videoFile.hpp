//
// Created by User on 15.6.2021 г..
//

#ifndef VERSION_1_VIDEOFILE_HPP
#define VERSION_1_VIDEOFILE_HPP

#include "audioFile.hpp"
#include <vector>

class VideoFile : public MultiMediaFile{
public:
    VideoFile(const std::string &name = "", size_t sizeMB = 0, const std::string &extension = "",
              const std::string &subs = "");

    void print_debug_state() override;

    MultiMediaFile *clone() override;
private:
    std::string subs;
    std::vector<AudioFile> audios;
};


#endif //VERSION_1_VIDEOFILE_HPP
