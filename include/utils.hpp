#ifndef UTIL_H
#define UTIL_H

#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitLine(const std::string& line, char delimiter); 
bool isPrefix(const std::string& str, const std::string& prefix);

#endif
