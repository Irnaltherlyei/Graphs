#include "EdgeTable.h"

std::string EdgeTable::toString() const
{
    std::stringstream ss;
    for (int i = 0; i < edges_.size(); i++) {
        if (edges_[i][2] != 0.0f) {
            ss << edges_[i][0] << ' ' << edges_[i][1] << ' '
                << edges_[i][2] << std::endl;
        }
    }
    return ss.str();
}
