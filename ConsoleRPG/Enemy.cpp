#include "Enemy.h"
#include "Player.h"
#include <iostream>

using namespace std;

// コンストラクタ
Enemy::Enemy(string enemyName, int enemyHp, int enemyAttack)
{
    name = enemyName;
    hp = enemyHp;
    attack = enemyAttack;
}

// 敵のステータス表示
void Enemy::ShowStatus()
{
    cout << "敵の名前：" << name << endl;
    cout << "HP：" << hp << endl;
    cout << "攻撃力：" << attack << endl;
}

// プレイヤーを攻撃
void Enemy::AttackPlayer(Player& player)
{
    cout << endl;
    cout << name << "の攻撃！" << endl;

    player.hp -= attack;

    if (player.hp < 0)
    {
        player.hp = 0;
    }

    cout << player.name << "に " << attack << " ダメージ！" << endl;
}