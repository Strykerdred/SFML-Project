#include "Enemy.h"

Enemy::Enemy()
{
	enemyShape.setRadius(20.0f);
	enemyShape.setFillColor(sf::Color::Red);
	enemyShape.setPosition(300, 300);
}

Enemy::~Enemy()
{
}

sf::CircleShape Enemy::GetShape()
{
	return enemyShape;
}
