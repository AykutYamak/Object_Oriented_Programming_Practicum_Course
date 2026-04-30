#pragma once
#include <iostream>
class Deserializable {
public:
	virtual std::ostream& deserialize(std::ostream& os) = 0;
};
std::ostream& operator>>(std::ostream& os, Deserializable& deserializable);
