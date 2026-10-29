#include "Event.h"


Event::Event()
{

}
Event::~Event()
{
}

void Event::GenerateEvent(Player& p)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 10;
	switch (i)
	{
	case 7:
		std::cout << " Kepp traveling..." <<std::endl;
	break;
	case 5:
		std::cout << "Puzzle encounter" << std ::endl;
		break;
	default:
	std::cout << "Enemy Encounter" << std::endl;
	EnemyEncounter(p);
	}
	
}

void Event::EnemyEncounter(Player& p)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	bool playerTurn = false;
	bool scape = false;
	bool PlayerDefending = false;
	int firstTurn = rand() % 100 + 1;
	if (firstTurn >= 50 - p.GetLuck())
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	std::cout << "------------------New enemy encounter -----------"<< std::endl;
	int level = p.GetLevel();
	int hp = p.GetLevel() * 10;
	
	int currentDamage = rand() % p.GetDamageMin() + 1;
	int defence = rand() % level;
	int exp = level * 10;
	baseEnemy = new Enemy("Damian", level, hp, exp, currentDamage , defence );
	while (!playerDefeated && !enemyDefeated && !scape)
	{
		if (playerTurn)
		{
			std::cout << "------------Your turn-----------" << std::endl;
			std::cout << "Choose your action" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Sheet" << std::endl;
			std::cout << "4: Show Enemy Stats" << std::endl;
			std::cout << "0: Scape" << std::endl;

			std::cin >> choice;
		    int scapeRand = (rand() % 100) + p.GetLuck();
		    int attackRoll = rand() % 100 + 1;
			switch (choice)
			{
			case 0:
				if (scapeRand > 50)
				{
					std::cout << " Escaped..." << std::endl;
					scape = true;
				}
				break;
			case 1:
				std::system("cls");
				if (attackRoll > (50 - p.GetStrenght()))
				{
					std::cout << "Player hit enemy" << std::endl;
					baseEnemy->TakeDamage(p.DoDamage());
					playerTurn = false;
				}
				break;
			case 2:
				PlayerDefending = true;
				playerTurn = false;

				break;
			case 3:
				p.PrintPlayerStats();
				playerTurn = true;
				break;
			case 4:
				baseEnemy->StatsEnemy();
				playerTurn = true;
				break;
			default:
				std::cout << "invalid option" << std::endl;
				break;
			};
			

		}
		else
		{
		   int  attackRoll = rand() % 100 + 1;
			std::cout << "--------------Enemy tourn-----------" << std::endl;
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "You win" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetExp() << std::endl;
				p.AddExp(baseEnemy->GetExp());
			}
			else
			{
				// tarea
				if (p.GetHp() <= 0)
				{
					std::cout << "You die  " << std::endl;
					playerDefeated = true;
				}
				
				 if (PlayerDefending && !playerDefeated)
				{
					if (attackRoll > 75)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;

					}
				}
				else
				{
					if (attackRoll > 45)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;

					}
				}
				
			}
			playerTurn = true;
		}
	 }
}

void Event::PuzzleEncounter(Player& p)
{
}
