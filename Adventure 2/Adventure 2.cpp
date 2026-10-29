
#include "Game.h"
#include <iostream>

int main()
{
    Game game;
    game.InitGame();
    while (game.GetPlaying())
    {
        game.mainMenu();
    }
    return 0;
}


