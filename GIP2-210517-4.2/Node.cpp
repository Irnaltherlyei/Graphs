#include "Node.h"

std::string Node::toString() const
{
    std::stringstream ss;
    ss << name_ << " [pos=\"" << x_ << "," << y_ << "!\"]";
    return ss.str();
}
