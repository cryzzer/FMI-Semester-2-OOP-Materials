//
// Created by User on 15.6.2021 г..
//

#include "multimediaPlayer.hpp"

MultimediaPlayer *MultimediaPlayer::instance() {
    static MultimediaPlayer player;
    return &player;
}

MultimediaPlayer::~MultimediaPlayer() {
    for(auto x : files){
        delete x;
    }
}

void MultimediaPlayer::addFile(MultiMediaFile *file) {
    files.push_back(file->clone());
}

void MultimediaPlayer::removeFile(size_t index) {
    if(index < files.size()){
        delete files[index];
        files.erase(files.begin()+index);
    }
}

void MultimediaPlayer::print_all_files_states(size_t index) {
    if(index < files.size()){
        files[index]->print_debug_state();
    }
}
