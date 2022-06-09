#pragma once
#include "IOrganismBase.h"

enum class EnemyType
{
	Cat,
	Wolf,
	Turtle,
	Max
};

struct EnemyStruct
{
	const std::string& name;
	int hp;
	int spd;
	EnemyType type;

	std::vector<AttackMove> atkMove;
};

class Enemy : public IOrganismBase
{
public:

	Enemy();
	~Enemy();
	void InitEnemy(const EnemyStruct& hstruct);
	void PrintEnemyData(const std::string& num);

	void SetEnemyType(EnemyType type);
	EnemyType GetEnemyType();

private:
	EnemyType m_enemyType;
};




