#include "Magic.hpp"
#include <cstring>
#pragma warning(disable:4996)

const char* Magic::getName() const {
    return name;
}
const char* Magic::getEffect() const {
    return effect;
}
Type Magic::getType() const {
    return type;
}
void Magic::setName(const char* name) {
    if (!name)
    {
        return;
    }
    strcpy(this->name, name);
}
void Magic::setEffect(const char* effect) {
    if (!effect)
    {
        return;
    }
    strcpy(this->effect, effect);
}
void Magic::setType(const Type type) {
    this->type = type;
}