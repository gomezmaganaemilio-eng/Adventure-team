#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"
//tarea
#include "Character.h"
class Event
{
public:
	Event();
	~Event();
	void GenerateEvent(Player& p);
	void EnemyEncounter(Player& p);
	void PuzzleEncounter(Player& p); //& es la referencia el * es el puntador
private:
	int numOfEvent;
	Enemy* baseEnemy;

};

