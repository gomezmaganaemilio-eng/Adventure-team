#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Event.h"
#include <fstream> // leer y escribir archivos
class Game
{
private: 
	Player player;
	/* al escribir Player y las clases con un nombre sencillo
	las podemos llamar y ponerles un punto para informar una funcion
	que tienen esas clases desde esta clase, muy fácil.*/
	Enemy* enemy;
	int choice;
	bool playing;
	Event v;
public:


	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void Travel();

	void SavePlayer();
	void LoadPlayer();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();

	void Levelup();
	void Skillup();

	bool GetPlaying();
};

