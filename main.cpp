#include <fmt/core.h>
#include <string>
#include <chrono>

#include "fileHandling.hpp"
#include "boyermoore.hpp"
#include "rabinkarp.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fmt::print(stderr, "no args provided\n");
        return -1;
    }

    std::string buf;
    std::string buf_file = "searchable.txt";
    importFile(buf, buf_file);

    std::string pattern;
    std::string pattern_file = "pattern.txt";
    importFile(pattern, pattern_file);

    if (argv[1] == "-bmh") {
        std::chrono::time_point bmh_start = std::chrono::high_resolution_clock::now();
        boyer_moore_horspool(pattern, buf);
        std::chrono::time_point bmh_end = std::chrono::high_resolution_clock::now();

        auto time_bmh = std::chrono::duration_cast<std::chrono::milliseconds>(bmh_end - bmh_start).count();

        return static_cast<int>(time_bmh);
    }
    else if (argv[1] == "-rk") {
        std::chrono::time_point rk_start = std::chrono::high_resolution_clock::now();
        rabin_karp(pattern, buf);
        std::chrono::time_point rk_end = std::chrono::high_resolution_clock::now();

        auto time_rk = std::chrono::duration_cast<std::chrono::milliseconds>(rk_end - rk_start).count();

        return static_cast<int>(time_rk);
    }

    return -1;
}
