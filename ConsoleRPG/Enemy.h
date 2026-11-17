#pragma once

#include <string>
using namespace std;

class Enemy
{
public:
    string name;
    int hp;
    int attack;

    Enemy(string enemyName, int enemyHp, int enemyAttack);

    void ShowStatus();

    // ƒvƒŒƒCƒ„[‚ğUŒ‚‚·‚é
    void AttackPlayer(class Player& player);
};