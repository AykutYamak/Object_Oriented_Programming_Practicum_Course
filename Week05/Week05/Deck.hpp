#pragma once
#include <iostream>
#include <functional>
#include "Monster.hpp"
#include "Magic.hpp"
const int MAX_MONSTER_COUNT = 20;
const int MAX_MAGIC_CARDS_COUNT = 20;

class Deck {
private:
    Monster monsters[MAX_MONSTER_COUNT];
    Magic magicCards[MAX_MAGIC_CARDS_COUNT];
    unsigned monsterCardsCount;
    unsigned magicCardsCount;

    template<typename T>
    void removeCardFromDeck(T array[], unsigned& arrayCardsCount, int index) {
        for (unsigned i = index + 1; i < arrayCardsCount; i++)
        {
            array[i - 1] = array[i];
        }
        arrayCardsCount--;
    }

public:
    Deck();

    const Monster* getMonsters() const;
    const Magic* getMagicCards() const;

    void setMonsters(Monster* monsters, int count);
    void setMagicCards(Magic* magicCards, int count);

    int getCountMagicCards() const;
    int getCountMonsterCards() const;

    void addMagicCardToDeck(Magic& magicCard);
    void addMonsterCardToDeck(Monster& monster);

    void changeMagicCardInDeck(int index, Magic& magic);
    void changeMonsterCardInDeck(int index, Monster& monster);

    void removeMagicCardFromDeck(int index);
    void removeMonsterCardFromDeck(int index);

    void sortMonsterCardsBy(std::function<bool(const Monster&, const Monster&)> f);
    void sortMagicCardsBy(std::function<bool(const Magic&, const Magic&)> f);
};