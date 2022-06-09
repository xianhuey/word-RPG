#pragma once
#include<vector>
#include<string>
#include<iostream>

#include "Hero.h"
#include "Enemy.h"

class OnBattle
{
public:
	static OnBattle* GetInstance();
	static void DestroyInstance();

	void InitDataOnEveryGame();

	void PrintAllHeroData();
	void PrintChosenDataAtkMoves();

	void Fight(int heroMoveIndex);
	bool IsFightEnd();
	bool isValidFightInput(int input);

	bool SetChosenHero(int id);
	void RandomizeEnemy();

	void PrintResult();
	
private:

	OnBattle();
	~OnBattle();

	void BattlePlayerAttack(int heroMoveIndex);
	void BattleEnemyAttack();
	void InitHeroList();
	void ClearRandomEnemyList();

	//Catalog
	std::vector<HeroStruct> m_heroesList;

	//InGameData
	std::vector<Enemy*> m_randomEnemyList;

	 Hero* m_chosenHero;
	static OnBattle* s_Instance;

	bool m_endGame = false;
};




