#pragma once
#include "Character.h"
#include <string>
#include <fstream>
class Player :
    public Character
{
    private:
        int strenght;
        int agility;
        int intelligence;
        int dexterity;
        int luck;

        int Maxesp;
        int skillPoints;
        public:
            Player();
            void InitPlayer(std::string name);
            void PrintPlayerStats();
            void LevelUp();

            int GetLuck() { return luck; }
            int GetStrenght() { return strenght; }
            int GetAgility() { return agility; }
            int GetDexterity() { return dexterity; }
            int GetIntelligence() { return intelligence; }
            int GetSkillPoints() { return skillPoints; }
            int GetMaxexp() { return Maxesp; }
            

            void SetStrenght(int S) { strenght = S; }
            void SetLuck(int l) { luck = l; }
            void SetAgility(int A) { agility = A; }
            void SetDexterity(int D) { dexterity = D; }
            void SetIntelligence(int I) { intelligence = I; }
            
            void AddStats(int stat, int value);

            void UpdateValues();
            void LoadStats(const std::string& filename);

            std:: string  SafeStats();
            ~Player();
};

