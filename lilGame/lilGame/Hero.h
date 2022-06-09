#pragma once
#include "IOrganismBase.h"
#include<map>

enum class HeroType
{
	Batman,
	Ultraman,
	Max
};

struct HeroStruct
{
	const std::string name;
	int hp; 
	int spd;
	HeroType type;
	std::vector<AttackMove> atkMove;
};

class Hero: public IOrganismBase
{
public:
	Hero();
	void InitHero(const HeroStruct& hstruct);
	void PrintHeroData(const std::string& num);
	void PrintChosenHeroMoves();

private:
	HeroType m_herotype;
};



