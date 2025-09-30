#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

#pragma once
class Player
{
public:
	Player();
	~Player();
	void Movement(const sf::RenderWindow& window);
	bool GetIsAlive();
	void Collision(Enemy& anEnemy);

	sf::CircleShape GetShape();

	void move(const sf::Vector2f& direction, const sf::RenderWindow& window);

private:
	bool pacmanDead = false;
	sf::CircleShape pacman;

protected:

};

