#include "Monster.hpp"
#include <cstring>
#pragma warning(disable:4996)

void Monster::free() {
    if (name)
    {
        delete[] name;
    }
    attackPoints = 1;
    deffencePoints = 1;
}
void Monster::copyFrom(const Monster& other) {
    attackPoints = other.attackPoints;
    deffencePoints = other.deffencePoints;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}
Monster::Monster() {
    name = nullptr;
    attackPoints = 1;
    deffencePoints = 1;
}
Monster::Monster(const Monster& other) {
    copyFrom(other);
}
Monster& Monster::operator=(const Monster& other) {
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
Monster::~Monster() {
    free();
}
int Monster::getAttacPoints() const {
    return attackPoints;
}
void Monster::setAttackPoints(int attackPoints) {
    if (attackPoints < 0)
    {
        return;
    }
    this->attackPoints = attackPoints;
}
int Monster::getDeffencePoints() const {
    return deffencePoints;
}
void Monster::setDeffencePoints(int deffencePoints) {
    if (deffencePoints < 0)
    {
        return;
    }
    this->deffencePoints = deffencePoints;
}
const char* Monster::getName() const {
    return name;
}
void Monster::setName(const char* name) {
    if (!name) return;
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}