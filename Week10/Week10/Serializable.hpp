#pragma once
#include <iostream>

class Serializable {
public:
	virtual std::ostream& serialize(std::ostream& os) const = 0;
};
std::ostream& operator<<(std::ostream & os, const Serializable & serialize);