#include <stdlib.h>    
#include <time.h>  

#include "OnBattle.h"
#include "EnemyFactory.h"

#define ENEMY_SKILL_COUNT 2


OnBattle::OnBattle()
{
	InitHeroList();
}

OnBattle::~OnBattle()
{
	ClearRandomEnemyList();

	if (m_chosenHero)
	{
		delete m_chosenHero;
		m_chosenHero = nullptr;
	}
}

OnBattle* OnBattle::GetInstance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new OnBattle();
	}
	return s_Instance;
}

void OnBattle::DestroyInstance()
{
	if (s_Instance == nullptr)
	{
		return;
	}

	delete(s_Instance);
	s_Instance = nullptr;
}

void OnBattle::InitDataOnEveryGame()
{
	m_endGame = false;
	m_randomEnemyList.clear();
}

void OnBattle::InitHeroList()
{
	m_chosenHero = new Hero();

	m_heroesList.push_back({
			"Batman",130,1,
			HeroType::Batman,
			std::vector<AttackMove>
	{ AttackMove{20,"蝙蝠效應"},AttackMove{50,"六塊腹肌"} }
		});

	m_heroesList.push_back({
			"UltraMan",150,1,
			HeroType::Ultraman,
			std::vector<AttackMove>
	{ AttackMove{30,"眼神死"},AttackMove{40,"鹹蛋攻擊"} }
		});
}

void OnBattle::PrintAllHeroData()
{
	int curCount = 1;

	for (int i=0;i<m_heroesList.size();i++)
	{
		
		std::cout << "\n英雄" << i+1 << " : \n"
			<< m_heroesList[i].name << " ";

		std::cout << "     " << "HP[" << m_heroesList[i].hp
			<< "] \n";

		int curCount = 1;

		for (int j=0;j<m_heroesList[i].atkMove.size();j++)
		{
			std::cout << "   ";

			std::cout << m_heroesList[i].atkMove[j].m_attackName
				<< "\tATK<" << m_heroesList[i].atkMove[j].m_atkHp << ">\n";
			curCount++;
		}
	}
}

void OnBattle::PrintChosenDataAtkMoves()
{
	m_chosenHero->PrintAttackMoves(true);
}

void OnBattle::Fight(int heroMoveIndex)
{
	if (IsFightEnd()) return;
	std::cout << "\n【你方攻擊！】\n";
	BattlePlayerAttack(heroMoveIndex);

	if (IsFightEnd()) return;
	std::cout << "\n【敵方攻擊！】\n";
	BattleEnemyAttack();
}

bool OnBattle::IsFightEnd()
{
	return m_endGame;
}

bool OnBattle::isValidFightInput(int input)
{
	if (input > 0 && input <= m_chosenHero->GetAtkMoveCount())
	{
		return true;
	}
	return false;
}

bool OnBattle::SetChosenHero(int id)
{
	int index = id - 1;
	if (index>=0 && index<m_heroesList.size()) 
	{
		m_chosenHero ->InitHero(m_heroesList[index]);
		return true;
	}

	return false;
}

//產怪
void OnBattle::RandomizeEnemy()
{
	int enemyCount = (rand() % (int)(EnemyType::Max))+1;
	
	ClearRandomEnemyList();
	for (int i=0;i<enemyCount;i++)
	{
		int index = rand() % (int)(EnemyType::Max);
		m_randomEnemyList.push_back(EnemyFactory::GetInstance()->CreateEnemy(index));
	}

	for (int i=0;i<m_randomEnemyList.size();i++)
	{
		m_randomEnemyList[i]->PrintEnemyData(std::to_string(i + 1));
	}

}

void OnBattle::ClearRandomEnemyList()
{
	for (int i=0;i<m_randomEnemyList.size();i++)
	{
		delete(m_randomEnemyList[i]);
	}
	m_randomEnemyList.clear();

}

void OnBattle::PrintResult()
{
	bool isWin = m_randomEnemyList.empty();
	if(isWin)
	{
		for (int i = 0; i < 20; i++) 
		{
			std::cout << "恭  喜  你  贏  了！\n";
		}
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			std::cout << "QQQQ 不 要 氣 餒！ QQQQ\n";
		}
	}
	std::cout << "\n再來一次嗎？\n1 Yes  2 No : ";
}

void OnBattle::BattlePlayerAttack(int heroMoveIndex)
{
	int heroAtk = m_chosenHero->GetAtkHp(heroMoveIndex);

	Enemy* vecIter ;
	for (auto iter = m_randomEnemyList.begin(); iter != m_randomEnemyList.end();)
	{
		vecIter = *iter;
		vecIter->UnderAttack(heroAtk, m_chosenHero->GetAtkName(heroMoveIndex));

		if (vecIter->isDead())
		{
			delete((*iter));
			iter = m_randomEnemyList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	if (m_randomEnemyList.empty())
	{
		m_endGame = true;
		return;
		//Player's Win
	}
}

void OnBattle::BattleEnemyAttack()
{
	for (auto iter = m_randomEnemyList.begin(); iter != m_randomEnemyList.end(); iter++)
	{
		int atkIndex = rand() % ENEMY_SKILL_COUNT;
		m_chosenHero->UnderAttack((*iter)->GetAtkHp(atkIndex)
			, (*iter)->GetAtkName(atkIndex));

		//check if hero is dead
		if (m_chosenHero->isDead())
		{
			m_endGame = true;
			return;
		}
	}
	std::cout << "\n";

}

OnBattle* OnBattle::s_Instance = nullptr;