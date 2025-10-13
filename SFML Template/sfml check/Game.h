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

	void CreateWall(std::vector<sf::RectangleShape>& walls, float x, float y, float width, float height, sf::Color color);

	sf::RenderWindow window{sf::VideoMode(800, 800), "Cap-Nam!" };

	int aboo(); //() betekent functie.
private:
	bool isRunning = true;
	Player player; // Add this line to define 'player'

protected:

};

