#include "Writer.h"

std::string Writer::toString() const
{
    std::stringstream ss;
    for (auto v : matrix) {
        for (auto f : v) {
            ss << std::setw(3) << f << " ";
        }
        ss << std::endl;
    }
    return ss.str();
}
