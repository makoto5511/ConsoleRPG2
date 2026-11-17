#include "GameManager.h"

// 最初は何もない
GameManager* GameManager::instance = nullptr;

// コンストラクタ
GameManager::GameManager()
{
    score = 0;
    playerLevel = 1;
}

// 唯一のGameManagerを取得
GameManager* GameManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new GameManager();
    }

    return instance;
}

// スコアを追加
void GameManager::AddScore(int value)
{
    score += value;
}

// スコアを取得
int GameManager::GetScore()
{
    return score;
}

// レベルアップ
void GameManager::AddLevel()
{
    playerLevel++;
}

// レベルを取得
int GameManager::GetLevel()
{
    return playerLevel;
}