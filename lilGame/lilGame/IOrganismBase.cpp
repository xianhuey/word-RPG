#include <stdlib.h>    
#include <time.h>  
#include <iomanip>

#include "IOrganismBase.h"


void IOrganismBase::AddAttackMove(const std::vector<AttackMove>& atkMove)
{
	m_atkMove = atkMove;
}

int  IOrganismBase::GetAtkHp(int atkIndex)
{

	if (atkIndex >= 0 && atkIndex < m_atkMove.size())
	{
		return m_atkMove[atkIndex].m_atkHp; 
	}
	else
	{
		std::cout << "Called Uninitialized AttackMove\n" ;
		return 0;
	}
}

std::string  IOrganismBase::GetAtkName(int atkIndex)
{
	if (atkIndex >= 0 && atkIndex < m_atkMove.size())
	{
		return m_atkMove[atkIndex].m_attackName;
	}
	else
	{
		std::cout << "Called Uninitialized AttackMove\n";
		return "¥¼ª¾";
	}
}

void  IOrganismBase::UnderAttack(int hpLosed, const std::string& atkName)
{
	bool atkSuceed = (rand() % (m_atkMove.size() * 2)) <= m_atkMove.size();

	if (atkSuceed) 
	{
		if (m_hp < hpLosed) 
		{
			m_hp = 0;
		}
		else
		{
			m_hp -= hpLosed;
		}
		
		std::cout << std::setw(9) << GetName() << "  ³Q" << std::setw(10) << atkName << "§ðÀ»¡A"
			<< "¦©¦å - " << hpLosed << "¡A³Ñ¾l " << std::setw(3) << m_hp;

		if (m_hp == 0) 
		{
			std::cout <<"  ****[WWW³QÀ»ÀÅWWW]****";
		}

	}
	else
	{
		std::cout << std::setw(9) << GetName() << "  «¢¡I ¸ú¹L¤@À»¡I"
			<< "            ¡A³Ñ¾l " << std::setw(3) << m_hp;
	}
	std::cout << "\n";

}

bool  IOrganismBase::isDead()
{
	return m_hp <= 0;
}

void IOrganismBase::PrintAllAttackInfo()
{
	std::cout << "     " << "HP[" << m_hp
		<< "] \n";

	PrintAttackMoves(false);
}

void IOrganismBase::PrintAttackMoves(bool withIndex)
{
	int curCount = 1;

	for (auto iter = m_atkMove.begin(); iter != m_atkMove.end(); iter++)
	{
		std::cout << "   ";
		if(withIndex)
		{
			std::cout << curCount << " ";
		}
		std::cout << iter->m_attackName
			<< "\tATK<" << iter->m_atkHp << ">\n";
		curCount++;
	}
}

int IOrganismBase::GetAtkMoveCount()
{
	return m_atkMove.size();
}

//void  IOrganismBase::SetHP(int hp)
//{
//	m_hp = hp;
//}
//
//int  IOrganismBase::GetHP()
//{
//	return m_hp;
//}
//
//void  IOrganismBase::SetSpd(int spd)
//{
//	m_spd = spd;
//}
//
//int  IOrganismBase::GetSpd()
//{
//	return m_spd;
//}
//
//void IOrganismBase::SetName(const std::string& name)
//{
//	m_name = name;
//}
//
//std::string IOrganismBase::GetName()
//{
//	return m_name;
//}
