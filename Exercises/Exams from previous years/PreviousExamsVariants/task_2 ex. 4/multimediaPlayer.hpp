//
// Created by User on 15.6.2021 г..
//

#ifndef VERSION_1_MULTIMEDIAPLAYER_HPP
#define VERSION_1_MULTIMEDIAPLAYER_HPP

#include "audioFile.hpp"
#include "videoFile.hpp"
#include "stream.hpp"


class MultimediaPlayer {
public:
    static MultimediaPlayer* instance();
    MultimediaPlayer(const MultimediaPlayer& rhs) = delete;
    MultimediaPlayer& operator=(const MultimediaPlayer& rhs) = delete;
    ~MultimediaPlayer();

    void addFile(MultiMediaFile* file);
    void removeFile(size_t index);

    void print_all_files_states(size_t index);

private:
    std::vector<MultiMediaFile*> files;

    MultimediaPlayer() = default;
};


#endif //VERSION_1_MULTIMEDIAPLAYER_HPP
