#pragma once

#include "OnBattle.h"
#include "StateMachine.h"
#include "States.h"
#include "Controller.h"

int main()
{
	srand(time(NULL));

	Controller gameController;
	
	StateMachine::GetInstance()->AddState(StateType::Menu,new MenuState());
	StateMachine::GetInstance()->AddState(StateType::ChooseCharacter, new ChooseCharacter());
	StateMachine::GetInstance()->AddState(StateType::CreateEnemy, new CreateEnemy());
	StateMachine::GetInstance()->AddState(StateType::Fight, new Fight());
	StateMachine::GetInstance()->AddState(StateType::Result, new Result());
	StateMachine::GetInstance()->AddState(StateType::Exit, new Exiting());

	StateMachine::GetInstance()->Transit(StateType::Menu);

	while (!gameController.GetToTerminate())
	{
		gameController.OnGoing();
	}

	OnBattle::GetInstance()->DestroyInstance();

	system("pause");
}