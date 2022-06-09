#pragma once
#include "StateType.h"

class IState
{
public:
	IState(StateType type);
	virtual void Tick() ; // 進程處理
	virtual void OnEnter() ; // 進入此狀態時處理
	virtual void OnExit(); // 離開此狀態時處理

	StateType GetStateType();

	void SetNextState(StateType nextState);
	StateType GetNextState();

private:

	StateType m_sType ;
	StateType m_nextState ;
};

