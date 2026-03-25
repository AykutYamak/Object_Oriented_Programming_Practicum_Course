#pragma once
#include "Deck.hpp"
#include <functional>
class Duelist {
private:
	char* name;
	Deck deck;

	void free();
	void copyFrom(const Duelist& other);

public:
	Duelist();
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();
	
	const char* getName() const;
	void setName(const char* name);
	int getCountMagicCards() const;
	int getCountMonsterCards() const;
	void addMagicCardToDeck(Magic& magicCard);
	void addMonsterCardToDeck(Monster& monster);
	void changeMagicCard(int index, Magic& magic);
	void changeMonsterCard(int index, Monster& monster);
	void removeMagicCard(int index);
	void removeMonsterCard(int index);
	void sortMagicCardsBy(std::function<bool(const Magic&, const Magic&)> f);
	void sortMonsterCardsBy(std::function<bool(const Monster&, const Monster&)> f);


};