#include "EnemyFactory.h"
#include "EnemyData.h"

// “G‚ğì¬‚·‚é
Enemy EnemyFactory::CreateEnemy(int enemyType)
{
    // ”ÍˆÍŠO‚È‚çƒXƒ‰ƒCƒ€
    if (enemyType < 0 || enemyType >= ENEMY_COUNT)
    {
        enemyType = 0;
    }

    EnemyData data = enemyTable[enemyType];

    return Enemy(data.name, data.hp, data.attack);
}