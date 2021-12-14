//
// Created by smacdonald on 11/03/2021.
//

#ifndef INC_201ASSESSMENT_BOYERMOORE_HPP
#define INC_201ASSESSMENT_BOYERMOORE_HPP

#endif //INC_201ASSESSMENT_BOYERMOORE_HPP

#include <array>

/*
 * An implementation of the Boyer-Moore-Horspool string searching algorithm
 */

int boyer_moore_horspool(const std::string& pattern, std::string& buf) {
    int pattern_length = pattern.size();
    int buffer_length = buf.size();

    std::array<int, 256> skip{};

    std::string found;

    for (int i = 0; i < 256; i++) {
        skip[i] = pattern_length;
    }
    for (int i = 0; i < pattern_length; i++) {
        skip[int(pattern[i])] = (pattern_length - 1) - i;
    }

    for (int i = 0; i < buffer_length; i++) {
        int s = skip[int(buf[i + pattern_length - 1])];
        if (s != 0) {
            i += s - 1;
            continue;
        }
        for (int j = 0; j < pattern_length; j++) {
            if (buf[i + j] != pattern[j]) {
                found.clear();
                break;
            }
            else {
                found += pattern[j];
            }
        }
        if (found == pattern) {
            return i;
        }
    }

    return -1;
}