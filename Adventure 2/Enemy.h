#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:
    
public:
    Enemy(std::string name, int l, int hp, int e, int damage,  int D);
    Enemy();
    void InitEnemy();
    void StatsEnemy();
    ~Enemy();
};

