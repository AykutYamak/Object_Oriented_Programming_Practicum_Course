#pragma once
class Monster {
private:
    char* name;
    unsigned int attackPoints;
    unsigned int deffencePoints;

    void free();
    void copyFrom(const Monster& other);

public:
    Monster();
    Monster(const Monster& other);
    Monster& operator=(const Monster& other);
    ~Monster();

    int getAttacPoints() const;
    void setAttackPoints(int attackPoints);
    int getDeffencePoints() const;
    void setDeffencePoints(int deffencePoints);
    const char* getName() const;
    void setName(const char* name);
};