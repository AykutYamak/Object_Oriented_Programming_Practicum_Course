#include "Deserializable.hpp"
#pragma disable (warning:4996)

std::ostream& operator>>(std::ostream& os, Deserializable& deserializable) {
	deserializable.deserialize(os);
	return os;
}