#include<iostream>
#include "Monster.hpp"
#include "Magic.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"
#pragma warning(disable:4996)
#pragma once

int main()
{
    Deck d;

    Monster blueEyes;
    blueEyes.setName("Blue-eyes white dragon");
    blueEyes.setAttackPoints(3000);
    blueEyes.setDeffencePoints(2500);

    d.addMonsterCardToDeck(blueEyes);

    Magic monsterReborn;
    monsterReborn.setName("Monster reborn");
    monsterReborn.setEffect("revive");
    monsterReborn.setType(Type::spell);

    d.addMagicCardToDeck(monsterReborn);

    std::cout << "Magic cards in d: " << d.getCountMagicCards() << "\n";     
    std::cout << "Monster cards in d: " << d.getCountMonsterCards() << "\n"; 

    std::cout << "-----------------------\n";

    Duelist player1;
    player1.setName("Seto Kaiba");

    Monster darkMagician;
    darkMagician.setName("Dark Magician");
    darkMagician.setAttackPoints(2500);
    darkMagician.setDeffencePoints(2100);

   
    player1.addMonsterCardToDeck(darkMagician);

    std::cout << player1.getName() << " added " << darkMagician.getName() << " to his deck!\n";

    Duelist player2;
    player2.setName("Yugi Muto");

    Magic reflection;
    reflection.setName("Reflection");
    reflection.setEffect("Reflects the last played spell");
    reflection.setType(Type::trap); 

    player2.addMagicCardToDeck(reflection);

    std::cout << player2.getName() << " set a trap card: " << reflection.getName() << "!\n";
    return 0;
}