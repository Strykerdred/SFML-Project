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

	void Update();
	//return type, functie naam ( argumenten );
	bool getIsRunning();

private:
	bool isRunning = false;

protected:


};
