#include "ObjectPool.h"
#include <iostream>

using namespace std;

// コンストラクタ
ObjectPool::ObjectPool()
{
    for (int i = 0; i < POOL_SIZE; i++)
    {
        messages[i] = "";
        used[i] = false;
    }
}

// 空いているオブジェクトを取得
int ObjectPool::GetObject()
{
    for (int i = 0; i < POOL_SIZE; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            return i;
        }
    }

    return -1;
}

// メッセージを設定
void ObjectPool::SetMessage(int index, string message)
{
    if (index >= 0 && index < POOL_SIZE)
    {
        messages[index] = message;
    }
}

// オブジェクトを解放
void ObjectPool::ReleaseObject(int index)
{
    if (index >= 0 && index < POOL_SIZE)
    {
        messages[index] = "";
        used[index] = false;
    }
}

// 現在使用中のメッセージを表示
void ObjectPool::ShowMessages()
{
    cout << endl;
    cout << "【戦闘ログ】" << endl;

    for (int i = 0; i < POOL_SIZE; i++)
    {
        if (used[i])
        {
            cout << messages[i] << endl;
        }
    }
}