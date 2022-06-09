#include "IState.h"
#include "StateType.h"
#include <iostream>

IState::IState (StateType type)
	: m_sType(type)
{
	m_nextState = StateType::Empty;
}

void IState::Tick()
{
}

void IState::OnEnter()
{
}

void IState::OnExit()
{
	m_nextState = StateType::Empty;
	std::cout << "\n\n=============================\n=============================\n\n";
}

StateType IState::GetStateType()
{
	return m_sType;
}

void IState::SetNextState(StateType nextState)
{
	m_nextState = nextState;
}

StateType IState::GetNextState()
{
	return m_nextState;
}
