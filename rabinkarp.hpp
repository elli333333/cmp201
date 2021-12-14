//
// Created by smacdonald on 11/03/2021.
//

#ifndef INC_201ASSESSMENT_RABINKARP_HPP
#define INC_201ASSESSMENT_RABINKARP_HPP

#endif //INC_201ASSESSMENT_RABINKARP_HPP

int rolling_hash(const std::string &text, int hash_constant) {
    int hash = 0;
    for (char c : text) {
        hash += (int(c) * hash_constant) % (hash_constant * 3);
    }
    return hash;
}

int rabin_karp(const std::string& pattern, std::string& buf) {
    int hash_constant = 10;
    int pattern_length = pattern.size();
    int pattern_hash = rolling_hash(pattern, hash_constant);

    for (int i = 0; i < buf.size(); ++i) {
        int buf_hash = rolling_hash(buf.substr(i, pattern_length), hash_constant);
        if (buf_hash - pattern_hash == 0) {
            if (buf.substr(i, pattern_length) == pattern) {
                return i;
            }
        }
    }
    return -1;
}