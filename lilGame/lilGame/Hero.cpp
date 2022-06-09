#include "Hero.h"

Hero::Hero()
{
	m_herotype = HeroType::Empty;
}

void Hero::InitHero(const HeroStruct& hstruct)
{
	SetHP(hstruct.hp);
	SetSpd(hstruct.spd);
	SetName(hstruct.name);
	m_herotype = hstruct.type;
	AddAttackMove(hstruct.atkMove);
}

void Hero::PrintHeroData(const std::string& num)
{
	std::cout << "\n­^¶¯" << num << " : \n"
		<< GetName() << " ";
	PrintAllAttackInfo();
}

void Hero::PrintChosenHeroMoves()
{
	PrintAttackMoves(true);
}
