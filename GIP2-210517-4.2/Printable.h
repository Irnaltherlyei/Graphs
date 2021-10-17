#pragma once

#include <string>
#include <iostream>
#include <sstream>

class Printable
{
public:
	virtual std::string toString() const = 0;
};

inline std::ostream& operator << (std::ostream& os, Printable* printable) {
	std::string s = printable->toString();
	os << s;
	return os;
}



