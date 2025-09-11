#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

#pragma once
class Player
{
public:
	Player();
	~Player();
	void Movement();
	bool GetIsAlive();
	void Collision(Enemy& anEnemy);

	sf::CircleShape GetShape();
	
private:
	bool pacmanDead = false;
	sf::CircleShape pacman;

protected:



};

