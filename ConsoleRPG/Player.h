#pragma once

#include <string>
using namespace std;

class Player
{
public:
    string name;
    int hp;
    int attack;

    Player(string playerName, int playerHp, int playerAttack);

    void ShowStatus();

    // “G‚ğUŒ‚‚·‚é
    void AttackEnemy(class Enemy& enemy);
};