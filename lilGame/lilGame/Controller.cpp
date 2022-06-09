#include "Controller.h"

Controller::Controller()
	:m_isToTerminate(false)
{
}

Controller::~Controller()
{
}

void Controller::OnGoing()
{
	IState* state = StateMachine::GetInstance()->GetCurrentState();
	if (state->GetNextState() == StateType::Empty)
	{
		state->Tick();
	}
	else
	{
		if(state->GetNextState()==StateType::GoingToTerminate)
		{
			m_isToTerminate = true;
			return;
		}
		SwitchState(state->GetNextState());
	}
}

bool Controller::GetToTerminate()
{
	return m_isToTerminate;
}

void Controller::SwitchState(StateType state)
{
	StateMachine::GetInstance()->Transit(state);
}
