#include "Game.h"
#include "Character.h"
Game::Game()
{
	this->playing = true;
}

Game::~Game()
{
}

void Game::InitGame()
{
	std::cout << "Starting the Game" << std::endl;
	std::cout << "Enter your username" << std::endl;
	NewPlayer();
}

void Game::mainMenu()
{
	std::cout << "------------------------Main MENU-----------------" << std::endl;
	std::cout << " 0: QuiteGame" << std::endl;
	std::cout << "1: Player Stats" << std::endl;
	std::cout << "2: Enemy Stats" << std::endl;
	std::cout << "3: Travel" << std::endl;
	std::cout << "4: Skill Up" << std:: endl;
	std::cout << "5: Level Up" << std:: endl;
	std::cout << "6: Save player progress" << std::endl;
	std::cout << "7: Load last play" << std::endl;
	

	std::cout << "Enter Choice" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->playing = false;
		break;
	case 1:
		PrintPlayerStats();
		break;
	case 2:
		NewEnemy();
		break;
	case 3:
		Travel();
		break;
	case 4:
		Skillup();
		break;
	case 5:
		Levelup();
		break;
	case 6:
		SavePlayer();
		
		break;
	case 7:
		LoadPlayer();
		
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::Travel()
{
	v.GenerateEvent(player);
}

void Game::SavePlayer()
{
	std::string FileName = "savePlayer.txt";
	std::ofstream outFile(FileName);
	if (outFile.is_open())
	{
		outFile << player.SafeStats() << " ";

	}
	else
	{
		std::cout << "Cant saved" << std::endl;
	}
	outFile.close();
	std::cout << "Saved!" << std::endl;
}

void Game::LoadPlayer()
{
	std::string fileName = "savePlayer.txt";
	player.LoadStats(fileName);
}

void Game::NewPlayer()
{
	player.InitPlayer("mochi");
}

void Game::NewEnemy()
{
	std::string name = "Zombie";
	srand(static_cast<unsigned int > (time(0)));
	int level = rand() % 10;
	int hp =  rand() %16;
	int xp = rand () % 100;
	int damage = rand() % 16;
	int defence = rand() % 10;
	enemy = new Enemy(name, level, hp, xp, damage, defence);
	enemy->StatsEnemy();

}

void Game::PrintPlayerStats()
{
	player.PrintPlayerStats();
}

bool Game::GetPlaying()
{
	return this->playing;
}
void Game::Levelup()
{
	player.LevelUp();
}

void Game::Skillup()
{
	while (player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints()
			<< " Points to use" << std::endl;
		std::cout << "---------Stats--------" << std::endl;
		std::cout << "1: Strenght" << std::endl;
		std::cout << "2: Agility" << std::endl;
		std::cout << "3: Intelligence" << std::endl;
		std::cout << "4: Luck" << std::endl;
		std::cout << "5: Dexterity" << std::endl;
		std::cin >> choice;
		player.AddStats(choice, 1);

	}
}
