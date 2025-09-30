#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:

    static bool CircleCollision(const sf::CircleShape& c1, const sf::CircleShape& c2);


    static void KeepCircleInBounds(sf::CircleShape& circle, const sf::RenderWindow& window);

private:

protected:
};