#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "GameManager.h"
#include "GameState.h"
#include "ObjectPool.h"

using namespace std;

int main()
{
    // ========================================
    // ゲームに必要なオブジェクトを作成
    // ========================================

    // プレイヤー
    Player player("勇者", 100, 20);

    // 敵
    Enemy enemy = EnemyFactory::CreateEnemy(2);

    // 戦闘ログ用オブジェクトプール
    ObjectPool logPool;

    // ゲーム状態
    GameState state = GameState::TITLE;


    // ========================================
    // ゲームループ
    // ========================================

    while (true)
    {

        int Enemy = 0;

        // ====================================
        // タイトル画面
        // ====================================

        if (state == GameState::TITLE)
        {
            cout << endl;
            cout << "============================" << endl;
            cout << "       コンソールRPG" << endl;
            cout << "============================" << endl;

            cout << "1. ゲーム開始" << endl;
            cout << "2. ゲーム終了" << endl;
            cout << "> ";

            int command;
            cin >> command;


            // ゲーム開始
            if (command == 1)
            {
                // プレイヤーを初期状態に戻す
                player.hp = 100;

                // 敵を作り直す
                enemy = EnemyFactory::CreateEnemy(Enemy);

                cout << endl;
                cout << "ゲームを開始します！" << endl;

                cout << endl;
                cout << enemy.name << "が現れた！" << endl;

                // 戦闘状態へ
                state = GameState::BATTLE;
            }

            // ゲーム終了
            else if (command == 2)
            {
                cout << endl;
                cout << "ゲームを終了します。" << endl;

                break;
            }

            // 間違った入力
            else
            {
                cout << endl;
                cout << "1か2を入力してください。" << endl;
            }
        }


        // ====================================
        // 戦闘
        // ====================================

        else if (state == GameState::BATTLE)
        {
            cout << endl;
            cout << "============================" << endl;
            cout << "          戦闘中" << endl;
            cout << "============================" << endl;

            cout << endl;

            cout << "【プレイヤー】" << endl;
            cout << "名前：" << player.name << endl;
            cout << "HP：" << player.hp << endl;
            cout << "攻撃力：" << player.attack << endl;

            cout << endl;

            cout << "【敵】" << endl;
            cout << "名前：" << enemy.name << endl;
            cout << "HP：" << enemy.hp << endl;
            cout << "攻撃力：" << enemy.attack << endl;

            cout << endl;
            cout << "----------------------------" << endl;

            cout << "1. 攻撃" << endl;
            cout << "2. 逃げる" << endl;

            cout << "> ";

            int command;
            cin >> command;


            // ==================================
            // 攻撃
            // ==================================

            if (command == 1)
            {
                // ------------------------------
                // プレイヤーの攻撃
                // ------------------------------

                player.AttackEnemy(enemy);


                // 戦闘ログをオブジェクトプールから取得
                int logIndex = logPool.GetObject();

                if (logIndex != -1)
                {
                    string message =
                        player.name + "が" + enemy.name + "を攻撃！";

                    logPool.SetMessage(logIndex, message);
                }


                // ------------------------------
                // 敵を倒したか確認
                // ------------------------------

                if (enemy.hp <= 0)
                {
                    cout << endl;
                    cout << enemy.name << "を倒した！" << endl;


                    // シングルトンからスコアを取得して加算
                    GameManager::GetInstance()->AddScore(100);

                    cout << "100ポイント獲得！" << endl;


                    // 勝利状態へ
                    state = GameState::VICTORY;
                }

                // ------------------------------
                // 敵が生きている場合
                // ------------------------------

                else
                {
                    // --------------------------
                    // 敵の反撃
                    // --------------------------

                    enemy.AttackPlayer(player);


                    // 戦闘ログを取得
                    int enemyLogIndex = logPool.GetObject();

                    if (enemyLogIndex != -1)
                    {
                        string message =
                            enemy.name + "が" +
                            player.name + "に反撃！";

                        logPool.SetMessage(
                            enemyLogIndex,
                            message
                        );
                    }


                    // --------------------------
                    // プレイヤーが倒れたか確認
                    // --------------------------

                    if (player.hp <= 0)
                    {
                        cout << endl;
                        cout << player.name
                            << "は倒れてしまった……"
                            << endl;

                        // ゲームオーバー状態へ
                        state = GameState::GAMEOVER;
                    }
                }


                // ------------------------------
                // 戦闘ログ表示
                // ------------------------------

                logPool.ShowMessages();


                // ------------------------------
                // 使用したログを解放
                // ------------------------------

                // もう一度使用できるようにする
                for (int i = 0; i < 5; i++)
                {
                    logPool.ReleaseObject(i);
                }
            }


            // ==================================
            // 逃げる
            // ==================================

            else if (command == 2)
            {
                cout << endl;
                cout << "戦闘から逃げた！" << endl;

                // タイトルへ戻る
                state = GameState::TITLE;
            }


            // ==================================
            // 間違った入力
            // ==================================

            else
            {
                cout << endl;
                cout << "1か2を入力してください。" << endl;
            }
        }


        // ====================================
        // 勝利
        // ====================================

        else if (state == GameState::VICTORY)
        {
            cout << endl;
            cout << "============================" << endl;
            cout << "        GAME CLEAR!" << endl;
            cout << "============================" << endl;

            cout << endl;

            // シングルトンからスコアを取得
            cout << "現在のスコア："
                << GameManager::GetInstance()->GetScore()
                << endl;

            cout << endl;

            cout << "1. タイトルに戻る" << endl;
            cout << "2. ゲーム終了" << endl;

            cout << "> ";

            int command;
            cin >> command;


            // タイトルに戻る
            if (command == 1)
            {

                player.hp = 100;

                enemy = EnemyFactory::CreateEnemy(0);

                state = GameState::TITLE;
            }

            // ゲーム終了
            else if (command == 2)
            {
                cout << endl;
                cout << "ゲームを終了します。" << endl;

                break;
            }

            else
            {
                cout << endl;
                cout << "1か2を入力してください。" << endl;
            }
        }


        // ====================================
        // ゲームオーバー
        // ====================================

        else if (state == GameState::GAMEOVER)
        {
            cout << endl;
            cout << "============================" << endl;
            cout << "        GAME OVER" << endl;
            cout << "============================" << endl;

            cout << endl;

            cout << "1. タイトルに戻る" << endl;
            cout << "2. ゲーム終了" << endl;

            cout << "> ";

            int command;
            cin >> command;


            // タイトルへ戻る
            if (command == 1)
            {
                // プレイヤーを復活
                player.hp = 100;

                // 新しい敵を作成
                enemy = EnemyFactory::CreateEnemy(0);

                state = GameState::TITLE;
            }

            // ゲーム終了
            else if (command == 2)
            {
                cout << endl;
                cout << "ゲームを終了します。" << endl;

                break;
            }

            else
            {
                cout << endl;
                cout << "1か2を入力してください。" << endl;
            }
        }
    }


    // ========================================
    // ゲーム終了
    // ========================================

    cout << endl;
    cout << "============================" << endl;
    cout << "       お疲れ様でした！" << endl;
    cout << "============================" << endl;

    return 0;
}