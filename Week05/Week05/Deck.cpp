#include "Deck.hpp"
#include <iostream>
#pragma warning(disable:4996)
Deck::Deck() {
    monsterCardsCount = 0;
    magicCardsCount = 0;
}
const Monster* Deck::getMonsters() const {
    return monsters;
}
const Magic* Deck::getMagicCards() const {
    return magicCards;
}
void Deck::setMonsters(Monster* monsters, int count) {
    for (int i = 0; i < count; i++)
    {
        this->monsters[i] = monsters[i];
    }
    monsterCardsCount = count;
}
void Deck::setMagicCards(Magic* magicCards, int count) {
    for (int i = 0; i < count; i++)
    {
        this->magicCards[i] = magicCards[i];
    }
    magicCardsCount = count;
}
int Deck::getCountMagicCards() const {
    return magicCardsCount;
}
int Deck::getCountMonsterCards() const {
    return monsterCardsCount;
} 
void Deck::addMagicCardToDeck(Magic& magicCard) {
    if (magicCardsCount == MAX_MAGIC_CARDS_COUNT)
    {
        std::cout << "Magic cards are already 20!" << std::endl;
        return;
    }
    magicCards[magicCardsCount] = magicCard;
    magicCardsCount++;
    std::cout << "Done adding magic card to deck!" << std::endl;
}
void Deck::addMonsterCardToDeck(Monster& monster) {
    if (monsterCardsCount == MAX_MONSTER_COUNT)
    {
        std::cout << "Monster cards are already 20!" << std::endl;
        return;
    }
    monsters[monsterCardsCount] = monster;
    monsterCardsCount++;
    std::cout << "Done adding monster card to deck!" << std::endl;
}
void Deck::changeMagicCardInDeck(int index, Magic& magic) {
    magicCards[index] = magic;
}
void Deck::changeMonsterCardInDeck(int index, Monster& monster) {
    monsters[index] = monster;
}
void Deck::removeMagicCardFromDeck(int index) {
    removeCardFromDeck<Magic>(magicCards, magicCardsCount, index);
}
void Deck::removeMonsterCardFromDeck(int index) {
    removeCardFromDeck<Monster>(monsters, monsterCardsCount, index);
}
void Deck::sortMonsterCardsBy(std::function<bool(const Monster&, const Monster&)> f) {
    for (unsigned i = 0; i < monsterCardsCount; i++)
    {
        for (unsigned j = 0; j < monsterCardsCount - i - 1; j++)
        {
            if (!f(monsters[j], monsters[j + 1]))
            {
                Monster temp = monsters[j];
                monsters[j] = monsters[j + 1];
                monsters[j + 1] = temp;
            }
        }
    }
}
void Deck::sortMagicCardsBy(std::function<bool(const Magic&, const Magic&)> f) {
    for (unsigned i = 0; i < magicCardsCount; i++)
    {
        for (unsigned j = 0; j < magicCardsCount - i - 1; j++)
        {
            if (!f(magicCards[j], magicCards[j + 1]))
            {
                Magic temp = magicCards[j];
                magicCards[j] = magicCards[j + 1];
                magicCards[j + 1] = temp;
            }
        }
    }
}