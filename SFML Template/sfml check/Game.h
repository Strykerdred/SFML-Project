#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include "Player.h"

class Game
{
public:
	Game();   //constructor
	~Game();  //destructor

	void Update();

	bool GetIsRunning();

	sf::RenderWindow window{sf::VideoMode(640, 480), "Cap-Nam!" };

	int aboo(); //() betekent functie.
private:
	bool isRunning = true;
	Player player; // Add this line to define 'player'

protected:

};

