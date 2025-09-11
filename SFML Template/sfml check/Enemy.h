#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{

public:

	Enemy();
	~Enemy();

	sf::CircleShape GetShape();

private:
	sf::CircleShape enemyShape;

protected:



};

