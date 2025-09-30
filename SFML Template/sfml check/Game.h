#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();

	//return type, functie naam ( argumenten );
	void Update();
	bool getIsRunning();

private:
	bool isRunning = false;

protected:


};
