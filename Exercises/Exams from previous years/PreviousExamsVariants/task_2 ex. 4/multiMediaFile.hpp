//
// Created by User on 15.6.2021 г..
//

#ifndef VERSION_1_MULTIMEDIAFILE_HPP
#define VERSION_1_MULTIMEDIAFILE_HPP

#include <string>


class MultiMediaFile {
public:
    MultiMediaFile() = default;
    MultiMediaFile(const std::string& name, size_t sizeMB, const std::string& extension);
    virtual ~MultiMediaFile() = default;
    virtual void print_debug_state() = 0;
    virtual MultiMediaFile* clone() = 0;
protected:
    std::string name;
    size_t sizeMB;
    std::string extension;
};


#endif //VERSION_1_MULTIMEDIAFILE_HPP
