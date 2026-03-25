#include "Duelist.hpp"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
void Duelist::free() {
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}

void Duelist::copyFrom(const Duelist& other) {
	if (other.name)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	else
	{
		this->name = nullptr;
	}
	this->deck = other.deck;
}

Duelist::Duelist() {
	name = nullptr;
}
Duelist::Duelist(const Duelist& other) {
	copyFrom(other);
}
Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
};
Duelist::~Duelist() {
	free();
}
const char* Duelist::getName() const {
	return this->name;
}
void Duelist::setName(const char* newName) {
	if (!newName) return;
	if (name)
	{
		delete[] name;
	}
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}
int Duelist::getCountMagicCards() const{
	return this->deck.getCountMagicCards();
}
int Duelist::getCountMonsterCards() const {
	return this->deck.getCountMonsterCards();
}
void Duelist::addMagicCardToDeck(Magic& magic) {
	deck.addMagicCardToDeck(magic);
}
void Duelist::addMonsterCardToDeck(Monster& monster) {
	deck.addMonsterCardToDeck(monster);
}
void Duelist::changeMagicCard(int index, Magic& magic) {
	deck.changeMagicCardInDeck(index, magic);
}
void Duelist::changeMonsterCard(int index, Monster& monster) {
	deck.changeMonsterCardInDeck(index, monster);
}
void Duelist::removeMagicCard(int index) {
	deck.removeMagicCardFromDeck(index);
}
void Duelist::removeMonsterCard(int index) {
	deck.removeMonsterCardFromDeck(index);
}
void Duelist::sortMagicCardsBy(std::function<bool(const Magic& magic1, const Magic& magic2)> f) {
	deck.sortMagicCardsBy(f);
}
void Duelist::sortMonsterCardsBy(std::function<bool(const Monster& monster1, const Monster& monster2)> f) {
	deck.sortMonsterCardsBy(f);
}

