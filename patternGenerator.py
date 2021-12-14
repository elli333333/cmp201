"""
script to generate searchable plain text files
ensures a known pattern is present at a known location
"""

import random
import sys


# if len(sys.argv) < 2:
#     FILE_LENGTH = 1024
# else:
#     arg = sys.argv[1]
#     arg = arg.removeprefix("-s=")
#     l = len(arg) - 1
#     FILE_LENGTH = int(arg[0: len(arg) - 1])
#     if arg[l] == "k":
#         FILE_LENGTH *= 1024
#     elif arg[l] == "M":
#         FILE_LENGTH *= 1024 ** 2
#     elif arg[l] == "G":
#         FILE_LENGTH *= 1024 ** 3


def write_file(filename, buf):
    with open(str(filename), "w") as filename:
        filename.write(str(buf))
    return "FILE_WRITTEN"


def str_insert(host, insert, where):
    host_a = host[:where]
    host_b = host[where:len(host)]
    return host_a + insert + host_b


def create_searchable_text(known_pattern, length, filename):
    with open(str(filename), "w") as filename:
        allowed_characters = ["A",
                              "C",
                              "G",
                              "T"]

        known_location = random.randint(0, length)

        for i in range(length):
            filename.write(random.choice(allowed_characters))
            if i == known_location:
                filename.write(known_pattern)

    return known_location


def create_pattern():
    buf = str()

    allowed_characters = ["A",
                          "C",
                          "G",
                          "T"]

    for i in range(random.randint(4, 256)):
        buf = buf + random.choice(allowed_characters)

    return buf


def main(file_size):

    file_length = 1
    if file_size[len(file_size) - 1] == "k":
        file_length *= 1024
    elif file_size[len(file_size) - 1] == "M":
        file_length *= 1024 ** 2
    elif file_size[len(file_size) - 1] == "G":
        file_length *= 1024 ** 3

    known_pattern = create_pattern()
    write_file(str("pattern.txt"), known_pattern)

    searchable_length = int(file_length)
    loc = create_searchable_text(known_pattern, searchable_length, "searchable.txt")
    pattern_end = loc + len(known_pattern)

    print(f"pattern {known_pattern} between {loc} and {pattern_end}")


# main()
