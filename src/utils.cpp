#include "utils.hpp"


std::vector<std::string> splitLine(const std::string& line, char delimiter) {
    std::vector<std::string> result {};
    std::stringstream ss {line};
    std::string item;
    
    while(std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}


bool isPrefix(const std::string& str, const std::string& prefix) {
    if (str.size() > prefix.size()) return false;
    return std::equal(str.begin(), str.end(), prefix.begin());

}
