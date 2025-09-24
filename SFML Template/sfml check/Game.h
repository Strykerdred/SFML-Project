#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 

class Game
{
public:
	Game();   //constructor
	~Game();  //destructor

	void Update();

	//structuur van de functie:
	//return type, functie naam, ( argumenten );
	bool GetIsRunning();


	sf::RenderWindow window{sf::VideoMode(640, 480), "Cap-Nam!" };

	int aboo(); //() betekent functie.
private:
	bool isRunning = true;

protected:

};

