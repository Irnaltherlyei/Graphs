#include "EdgeTable.h"

std::string EdgeTable::toString() const
{
    std::stringstream ss;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] == 1.0f && i <= j) {
                //ss << nodes_[i]->name_ << " -- " << nodes_[j]->name_ << std::endl;
                ss << i << ' ' << j << ' ' << std::endl;
            }
        }
    }
    return ss.str();
}
