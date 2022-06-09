#pragma once
#include<vector>
#include<string>
#include<iostream>

#define GETSET(type,member,name)\
type Get##name(){\
	return member;}\
void Set##name(type data){member=data;}

struct AttackMove
{
	int m_atkHp;
	std::string m_attackName;
};

class IOrganismBase
{
public:

	void AddAttackMove(const std::vector<AttackMove>& atkMove);
	int GetAtkHp(int atkId);
	std::string GetAtkName(int atkId);

	void UnderAttack(int hpLosed,const std::string& atkName);
	bool isDead();

	void PrintAllAttackInfo();
	void PrintAttackMoves(bool withIndex=false);

	int GetAtkMoveCount();

	GETSET(int, m_hp, HP);
	GETSET(int, m_spd, Spd);
	GETSET(std::string, m_name, Name);

private:

	int m_hp = 100;
	int m_spd = 1;

	std::vector<AttackMove> m_atkMove;
	std::string m_name;
};

