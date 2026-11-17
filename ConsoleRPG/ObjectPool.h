#pragma once

#include <string>
using namespace std;

class ObjectPool
{
private:
    static const int POOL_SIZE = 5;

    string messages[POOL_SIZE];
    bool used[POOL_SIZE];

public:
    ObjectPool();

    int GetObject();
    void SetMessage(int index, string message);
    void ReleaseObject(int index);
    void ShowMessages();
};