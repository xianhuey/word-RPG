#pragma once
#include "IState.h"
#include "StateType.h"


class MenuState : public IState
{
public:
	MenuState();
	virtual void Tick(); 
	virtual void OnEnter();
};

class ChooseCharacter : public IState
{
public:

	ChooseCharacter();

	virtual void Tick();
	virtual void OnEnter();
};

class CreateEnemy : public IState
{
public:
	CreateEnemy();

	virtual void Tick();
	virtual void OnEnter();
};

class Fight : public IState
{
public:
	Fight();

	virtual void Tick();
	virtual void OnEnter();
	//virtual void OnExit();

};

class Result : public IState
{
public:
	Result();

	virtual void Tick();
	virtual void OnEnter();
};

class Exiting : public IState
{
public:
	Exiting();

	virtual void Tick();
	virtual void OnEnter();
};

class GoingToTerminate : public IState
{
public:
	GoingToTerminate();

	virtual void Tick();
	virtual void OnEnter();
};
