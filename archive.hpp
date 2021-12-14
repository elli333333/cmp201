//
// Created by smacdonald on 25/03/2021.
//

#ifndef INC_201ASSESSMENT_ARCHIVE_HPP
#define INC_201ASSESSMENT_ARCHIVE_HPP

#endif //INC_201ASSESSMENT_ARCHIVE_HPP

int naive_skipping_search(const std::string& pattern, std::string& buf) {
    std::string found;
    for (int i = 0; i < buf.size(); i++) {
        for (int j = 0; j < pattern.size(); j++) {
            if (buf[i+j] == pattern[j]) {
                found += pattern[j];
            }
            else {
                found.clear();
                i += j;
                break;
            }
        }
        if (found == pattern) {
            return i;
        }
    }
}

int improved_skipping(const std::string& pattern, std::string& buf) {
    int pattern_length = pattern.size();
    int buffer_length = buf.size();

    std::array<bool, 256> pattern_table{};
    for (char c : pattern) {
        pattern_table[int(c)] = true;
    }

    std::string found;

    for (int i = 0; i < (buffer_length - pattern_length); i++) {
        if (!pattern_table[int(buf[i + pattern_length - 1])]) {
            i += (pattern_length - 1);
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