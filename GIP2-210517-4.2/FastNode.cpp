#include "FastNode.h"

std::string FastNode::toString() const
{
    std::string s = Node::toString();
    s.insert(s.size() - 1, ",shape=box");
    return s;
}
