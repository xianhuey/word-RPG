#pragma once
#include "StateMachine.h"
#include "States.h"

class Controller
{
public:
	Controller();
	~Controller();
	void OnGoing();
	bool GetToTerminate();

private:

	void SwitchState(StateType state);
	bool m_isToTerminate;
};

