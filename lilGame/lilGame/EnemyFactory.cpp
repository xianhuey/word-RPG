#include "EnemyFactory.h"
#include "Enemy.h"

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}


EnemyFactory* EnemyFactory::GetInstance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new EnemyFactory();
	}

	return s_Instance;
}

void EnemyFactory::DestroyInstance()
{
	if (s_Instance == nullptr)
	{
		return;
	}
	delete(s_Instance);
	s_Instance = nullptr;
}

Enemy* EnemyFactory::CreateEnemy(int intType)
{
	EnemyType type= static_cast<EnemyType>(intType);
	switch (type)
	{
	case EnemyType::Cat:
		return CatEnemy();
	case EnemyType::Wolf:
		return WolfEnemy();
	case EnemyType::Turtle:
		return TurtleEnemy();
	default:
		std::cout << " ERROR::Unknown ENEMY CALLED\n";
		return CatEnemy();
	}
	return CatEnemy();
}



Enemy* EnemyFactory::CatEnemy()
{
	Enemy* cat = new Enemy();
	cat->InitEnemy(EnemyStruct{
			"CAT",80,1,
			EnemyType::Cat,
			std::vector<AttackMove>
	{ AttackMove{10," ¼»¼b "},AttackMove{20,"Øp¤ý®ð¶Õ"} }
		});

	return cat;
}

Enemy* EnemyFactory::WolfEnemy()
{
	Enemy* wolf = new Enemy();
	wolf->InitEnemy(EnemyStruct{
			"WOLF",100,1,
			EnemyType::Wolf,
			std::vector<AttackMove>
	{ AttackMove{15,"¦y¾U¤ú¾¦"},AttackMove{28,"´Ý¼É¯T¤ö"} }
		});

	return wolf;
}

Enemy* EnemyFactory::TurtleEnemy()
{
	Enemy* turtle = new Enemy();
	turtle->InitEnemy(EnemyStruct{
			"TURTLE",200,1,
			EnemyType::Turtle,
			std::vector<AttackMove>
	{ AttackMove{15,"§ÔªÌÀt´ß"},AttackMove{25," ¿ð½w "} }
		});

	return turtle;
}

EnemyFactory* EnemyFactory::s_Instance = nullptr;
