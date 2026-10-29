#pragma once
#include <iostream>
class Character
{
private:
	std::string name;
	int level;
	int hp;
	int exp;
	int damageMin;
	int damageMax;
	int defence;
public:
	Character();
	virtual ~Character();
	void InitCharacter(std::string N);
	void PrintStats();

	//gets

	std::string GetName() { return name; }
	int GetLevel() { return level; }
	int GetHp() { return hp; }
	int GetExp() { return exp; }
	int GetDamageMin() { return damageMin; }
	int GetDamageMax() { return damageMax; }
	int GetDefence() { return defence; }

	//Aún cuando tengamos un get, también sets.

	void SetLevel(int l) { level = l; }
	void SetHp(int h) { hp = h; }
	void SetExp(int e) { exp = e; }
	void SetDamageMin(int DMin) { damageMin = DMin; }
	void SetDamageMax(int DMax) { damageMax = DMax; }
	void SetDefence(int D) { defence = D; }
	void SetName(std::string n) { name = n; }
	void AddExp(int xp) { exp += xp; }

	void TakeDamage(int d);
	const int DoDamage();

	bool IsAlive();
	
protected:

};

