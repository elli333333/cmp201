//
// Created by smacdonald on 11/03/2021.
//

#ifndef INC_201ASSESSMENT_FILEHANDLING_HPP
#define INC_201ASSESSMENT_FILEHANDLING_HPP

#endif //INC_201ASSESSMENT_FILEHANDLING_HPP

#include <iostream>
#include <fstream>

void importFile(std::string &localString, const std::string &filePath) {
    std::ifstream textFile;
    textFile.open(filePath, std::ios::in);

    if (textFile.is_open()) {
        std::string buf;
        while (getline(textFile, buf)) {
            localString += buf;
        }
        textFile.close();
    }
    else {
        fmt::print("unable to open file");
    }
}