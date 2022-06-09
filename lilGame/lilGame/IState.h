#pragma once
#include "StateType.h"

class IState
{
public:
	IState(StateType type);
	virtual void Tick() ; // �i�{�B�z
	virtual void OnEnter() ; // �i�J�����A�ɳB�z
	virtual void OnExit(); // ���}�����A�ɳB�z

	StateType GetStateType();

	void SetNextState(StateType nextState);
	StateType GetNextState();

private:

	StateType m_sType ;
	StateType m_nextState ;
};

