#pragma once

enum class KEY_TYPE
{
    UP,
    DOWN,
    LEFT,
    RIGHT,

    SPACE,
    ESC,

    Z,
    X,
    C,
    V,

    _0,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,

    END,
};

enum class KEY_STATE
{
    TAP,
    PRESSED,
    RELEASE,
    NONE,
};

struct tKeyInfo
{
    KEY_TYPE key;
    KEY_STATE state;
    bool bPrev;
};

class CKeyManager :
    public CSingleton<CKeyManager>
{
    SINGLE(CKeyManager)

private:
    vector<tKeyInfo> VecKey;

public:
    void KeyManagerInit();
    void KeyManagerTick();

public:
    KEY_STATE GetKeyState(KEY_TYPE _key) { return VecKey[(unsigned int)_key].state; }
};

