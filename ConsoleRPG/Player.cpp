#include "Player.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

// コンストラクタ
Player::Player(string playerName, int playerHp, int playerAttack)
{
    name = playerName;
    hp = playerHp;
    attack = playerAttack;
}

// ステータス表示
void Player::ShowStatus()
{
    cout << "名前：" << name << endl;
    cout << "HP：" << hp << endl;
    cout << "攻撃力：" << attack << endl;
}

// 敵を攻撃
void Player::AttackEnemy(Enemy& enemy)
{
    cout << endl;
    cout << name << "の攻撃！" << endl;

    enemy.hp -= attack;

    if (enemy.hp < 0)
    {
        enemy.hp = 0;
    }

    cout << enemy.name << "に " << attack << " ダメージ！" << endl;
}