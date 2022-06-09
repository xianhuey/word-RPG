#pragma once
#include<map>
#include "StateType.h"
#include "IState.h"


class StateMachine
{
public:
	static StateMachine* GetInstance();
	static void DestroyInstance();

	bool AddState(StateType type,IState* state); // 加入state
	bool Transit(StateType stateType); // 改變狀態
	void Tick(); // 進程處理
	IState* GetCurrentState();

	void ClearStateList();

private:

	StateMachine();
	~StateMachine();

	std::map<StateType,IState*> m_stateMap;
	IState* m_currentState = nullptr;
	StateType m_nextState;

	static StateMachine* s_Instance;
};

