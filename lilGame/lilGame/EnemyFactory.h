#pragma once
#include "Enemy.h"

class EnemyFactory
{
public:
	static EnemyFactory* GetInstance();
	static void DestroyInstance();

	Enemy* CreateEnemy(int intType);

private:
	EnemyFactory();
	~EnemyFactory();

	Enemy* CatEnemy();
	Enemy* WolfEnemy();
	Enemy* TurtleEnemy();

	static EnemyFactory* s_Instance;
};

