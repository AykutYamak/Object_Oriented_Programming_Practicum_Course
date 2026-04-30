#include "Serializable.hpp";
#pragma disable (warning:4669);

std::ostream& operator<<(std::ostream& os, const Serializable& serializable) {
	serializable.serialize(os);
	return os;
}