#include "EdgeTable.h"

std::string EdgeTable::toString() const
{
    std::stringstream ss;
    // Using matrix
    //for (int i = 0; i < matrix.size(); i++) {
    //    for (int j = 0; j < matrix.size(); j++) {
    //        if (matrix[i][j] > 0.0f && i <= j) {
    //            //ss << nodes_[i]->name_ << " -- " << nodes_[j]->name_ << std::endl;
    //            ss << i << ' ' << j << ' ' << matrix[i][j] <<std::endl;
    //        }
    //    }
    //}
    // Using edges_
    for (int i = 0; i < edges_.size(); i++) {
        if (edges_[i][2] != 0.0f) {
            ss << edges_[i][0] << ' ' << edges_[i][1] << ' '
                << edges_[i][2] << std::endl;
        }
    }
    return ss.str();
}
