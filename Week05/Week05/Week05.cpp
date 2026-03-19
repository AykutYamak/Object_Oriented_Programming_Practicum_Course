#include <iostream>
#include <cmath>
#include <cstring>
#pragma warning(disable:4996)

class Monster {
private:
    char* name;
    unsigned int attackPoints;
    unsigned int deffencePoints;
    void free() {
        if (name)
        {
            delete[] name;
        }
        attackPoints = 1;
        deffencePoints = 1;
    }
    void copyFrom(const Monster& other) {
        attackPoints = other.attackPoints;
        deffencePoints = other.deffencePoints;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
public:
    Monster() {
        name = nullptr;
        attackPoints = 1;
        deffencePoints = 1;
    }
    Monster(const Monster& other) {
        copyFrom(other);
    }
    Monster& operator=(const Monster& other) {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    ~Monster() {
        free();
    }
    int getAttacPoints() const {
        return attackPoints;
    }
    void setAttackPoints(int attackPoints) {
        if (attackPoints<0)
        {
            return;
        }
        this->attackPoints = attackPoints;
    }
    int getDeffencePoints() const {
        return deffencePoints;
    }
    void setDeffencePoints(int deffencePoints) {
        if (deffencePoints < 0)
        {
            return;
        }
        this->deffencePoints = deffencePoints;
    }
    const char* getName() const {
        return name;
    }
    void setName(const char* name) {
        if (!name) return;
        if (this->name!=nullptr)
        {
            delete[] this->name;
        }
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
};
enum Type {
    trap,
    buff,
    spell
};
const int MAX_NAME_SIZE = 26;
const int MAX_EFFECT_SIZE = 101;
class Magic {
private:
    char name[MAX_NAME_SIZE];
    char effect[MAX_EFFECT_SIZE];
    Type type;
public:
   /* Magic(const Magic& other) {
        setName(other.name);
        setEffect(other.effect);
        setType(other.type);
    }
    Magic& operator=(const Magic& other) {
        if (this!=&other)
        {
            setName(other.name);
            setEffect(other.effect);
            setType(other.type);
        }
        return *this;
    }*/
    const char* getName() const {
        return name;
    }
    const char* getEffect() const {
        return effect;
    }
    const Type getType() const {
        return type;
    }
    void setName(const char* name) {
        if (!name)
        {
            return;
        }
        strcpy(this->name, name);
    }
    void setEffect(const char* effect) {
        if (!effect)
        {
            return;
        }
        strcpy(this->effect, effect);
    }
    void setType(const Type type) {
        this->type = type;
    }

};
const int MAX_MONSTER_COUNT = 20;
const int MAX_MAGIC_CARDS_COUNT = 20;
class Deck {
    Monster monsters[MAX_MONSTER_COUNT];
    Magic magicCards[MAX_MAGIC_CARDS_COUNT];
    unsigned monsterCardsCount;
    unsigned magicCardsCount;
    
    template<typename T>
    void removeCardFromDeck(T array[], unsigned& arrayCardsCount, int index) {
        for (int i = index + 1; i < arrayCardsCount; i++)
        {
            array[i - 1] = array[i];
        }
        arrayCardsCount--;
    }
public:
    const Monster* getMonsters() const{
        return monsters;
    }
    const Magic* getMagicCards() const{
        return magicCards;
    }
    void setMonsters(Monster* monsters, int count) {
        for (int i = 0; i < count; i++)
        {
            this->monsters[i] = monsters[i];
        }
        monsterCardsCount = count;
    }
    void setMagicCards(Magic* magicCards, int count) {
        for (int i = 0; i < count; i++)
        {
            this->magicCards[i] = magicCards[i];
        }
        magicCardsCount = count;
    }
    int getCountMagicCards() const {
        return magicCardsCount;
    }
    int getCountMonsterCards() const {
        return monsterCardsCount;
    }
    void addMagicCardToDeck(Magic& magicCard) {
        if (magicCardsCount == MAX_MAGIC_CARDS_COUNT)
        {
            std::cout << "Magic cards are already 20!" << std::endl;
            return;
        }
        magicCards[magicCardsCount + 1] = magicCard;
        std::cout << "Done adding magic card to deck!" << std::endl;
    }
    void addMonsterCardToDeck(Monster& monster) {
        if (monsterCardsCount == MAX_MONSTER_COUNT)
        {
            std::cout << "Monster cards are already 20!" << std::endl;
            return;
        }
        monsters[monsterCardsCount + 1] = monster;
        std::cout << "Done adding monster card to deck!" << std::endl;
    }
    void changeMagicCardInDeck(int index, Magic& magic) {
        magicCards[index] = magic;
    }
    void changeMonsterCardInDeck(int index, Monster& monster) {
        monsters[index] = monster;
    }
    void removeMagicCardFromDeck(int index) {
        removeCardFromDeck<Magic>(magicCards,magicCardsCount, index);
    }
    void removeMonsterCardFromDeck(int index) {
        removeCardFromDeck<Monster>(monsters, monsterCardsCount, index);
    }

};
int main()
{
    std::cout << "Hello World!\n";
}