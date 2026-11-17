#pragma once

class GameManager
{
private:
    // シングルトン用
    static GameManager* instance;

    // ゲーム情報
    int score;
    int playerLevel;

    // 外部から直接作れないようにする
    GameManager();

public:
    // 唯一のインスタンスを取得
    static GameManager* GetInstance();

    // スコア
    void AddScore(int value);
    int GetScore();

    // レベル
    void AddLevel();
    int GetLevel();
};
