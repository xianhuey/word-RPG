#include "States.h"
#include "OnBattle.h"
#include<iostream>

#define START_GAME_OPTION 1
#define END_GAME_OPTION 2

MenuState::MenuState() :IState(StateType::Menu) {}

void MenuState::Tick()
{
	int input;
	std::cin >> input;

	if (std::cin.fail())
	{
		std::cout << "Please enter integer value! \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	
	if (input == START_GAME_OPTION )
	{
		SetNextState(StateType::ChooseCharacter);
		return;
	}

	if (input == END_GAME_OPTION)
	{
		SetNextState(StateType::Exit);
		return;
	}

	std::cout << "InputEror\n";

}

void MenuState::OnEnter()
{
	IState::OnEnter();

	std::cout << "\n\n\n\n來一局吧\n"
		<< "1. 好啊\n2. 不要 \n";
}

ChooseCharacter::ChooseCharacter() :IState(StateType::ChooseCharacter) {}

void ChooseCharacter::Tick()
{
	int input;
	std::cin >> input;

	if (std::cin.fail())
	{
		std::cout << "Please enter integer value! \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	if (!(OnBattle::GetInstance()->SetChosenHero(input)))
	{
		std::cout << "Wrong Input~!TryAgain\n";
		return;
	}

	SetNextState(StateType::CreateEnemy);
}

void ChooseCharacter::OnEnter()
{
	OnBattle::GetInstance()->InitDataOnEveryGame();
	OnBattle::GetInstance()->PrintAllHeroData();

	std::cout << "\n選擇你的英雄(數字): ";
}

//////////////////////////////////////////////////////////////////////

CreateEnemy::CreateEnemy() :IState(StateType::CreateEnemy) {}

void CreateEnemy::Tick()
{
	SetNextState(StateType::Fight);
}

void CreateEnemy::OnEnter()
{
	IState::OnEnter();

	std::cout << "你的對手已產生: \n";

	OnBattle::GetInstance()->RandomizeEnemy();
}

//////////////////////////////////////////////////////////////////////

Fight::Fight() :IState(StateType::Fight) {}

void Fight::Tick()
{
	std::cout << "***************************************\n";
	OnBattle::GetInstance()->PrintChosenDataAtkMoves();
	std::cout << "\n\n選擇招數:  ";

	int input;
	std::cin >> input;

	do
	{
		if (std::cin.fail())
		{
			std::cout << "Please enter integer value! \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

		if (OnBattle::GetInstance()->isValidFightInput(input) == false)
		{
			break;
		}

		OnBattle::GetInstance()->Fight(input - 1);

		if (OnBattle::GetInstance()->IsFightEnd())
		{
			SetNextState(StateType::Result);
			std::cout << "endgame";
		}
	} while (false);

}

void Fight::OnEnter()
{
	IState::OnEnter();
}

//////////////////////////////////////////////////////////////////////

Result::Result() :IState(StateType::Result) {}

void Result::Tick()
{
	int input;
	std::cin >> input;

	do {
		if (std::cin.fail())
		{
			std::cout << "Please enter integer value! \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

		if (input == START_GAME_OPTION)
		{
			SetNextState(StateType::ChooseCharacter);
			break;
		}
		
		if (input == END_GAME_OPTION)
		{
			SetNextState(StateType::Exit);
			break;
		}

		std::cout << "InputEror\n";

	} while (false);
}

void Result::OnEnter()
{
	IState::OnEnter();
	OnBattle::GetInstance()->PrintResult();
}

//////////////////////////////////////////////////////
Exiting::Exiting() :IState(StateType::Exit) {}

void Exiting::Tick()
{
	SetNextState(StateType::GoingToTerminate);
}

void Exiting::OnEnter()
{
	IState::OnEnter();

	std::cout << "OKBYE!\n\n";
}

GoingToTerminate::GoingToTerminate() :IState(StateType::GoingToTerminate) {}

void GoingToTerminate::Tick()
{
}

void GoingToTerminate::OnEnter()
{
}
