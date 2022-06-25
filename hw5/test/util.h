/*
 * DO NOT MAKE ANY CHANGES
 */

#ifndef UTIL
#define UTIL

#include <string>

std::string case_id(int id) {
    return "case " + std::to_string(id) + " failed.";
}

std::string case_id(int id1, int id2) {
    return "case (" + std::to_string(id1) + ", " + std::to_string(id2) + ") failed.";
}

#endif