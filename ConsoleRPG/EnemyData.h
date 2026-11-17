#pragma once

#include <string>
using namespace std;

// 敵のデータ
struct EnemyData
{
    string name;
    int hp;
    int attack;
};

// 敵データテーブル
const EnemyData enemyTable[] =
{
    {"スライム", 50, 10},
    {"ゴブリン", 80, 15},
    {"オーク", 120, 20},
    {"ドラゴン", 200, 30}
};

// 敵の種類数
const int ENEMY_COUNT = 4;
