#include "SlowNode.h"

std::string SlowNode::toString() const
{
    std::string s = Node::toString();
    s.insert(s.size() - 1, ",shape=circle");
    return s;
}