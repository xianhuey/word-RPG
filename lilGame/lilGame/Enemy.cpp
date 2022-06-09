#include "Enemy.h"

Enemy::Enemy():IOrganismBase()
{
	m_enemyType = EnemyType::Cat;
}

Enemy::~Enemy()
{
}

void Enemy::InitEnemy(const EnemyStruct& hstruct)
{
	SetHP(hstruct.hp);
	SetSpd(hstruct.spd);
	SetName(hstruct.name);
	SetEnemyType( hstruct.type);
	AddAttackMove((hstruct.atkMove));
}

void Enemy::PrintEnemyData(const std::string& num)
{
	std::cout << "\n¼Ä¤H" << num << " : " << GetName() << " ";
	PrintAllAttackInfo();
}

void Enemy::SetEnemyType(EnemyType type)
{
	m_enemyType = type;
}

EnemyType Enemy::GetEnemyType()
{
	return m_enemyType;
}
