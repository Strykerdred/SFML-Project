#include "Collision.h"

bool Collision::CircleCollision(const sf::CircleShape& c1, const sf::CircleShape& c2)
{
    sf::Vector2f pos1 = c1.getPosition();
    sf::Vector2f pos2 = c2.getPosition();
    float dx = pos1.x - pos2.x;
    float dy = pos1.y - pos2.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    float radiusSum = c1.getRadius() + c2.getRadius();
    return distance < radiusSum;
}

void Collision::KeepCircleInBounds(sf::CircleShape& circle, const sf::RenderWindow& window)
{
    float radius = circle.getRadius();
    sf::Vector2f pos = circle.getPosition();

    // Clamp X
    if (pos.x < radius)
        pos.x = radius;
    else if (pos.x > window.getSize().x - radius)
        pos.x = window.getSize().x - radius;

    // Clamp Y
    if (pos.y < radius)
        pos.y = radius;
    else if (pos.y > window.getSize().y - radius)
        pos.y = window.getSize().y - radius;

    circle.setPosition(pos);
}

void updatePlayerPosition(sf::CircleShape& player, const sf::Vector2f& velocity, const sf::RenderWindow& window)
{
    player.move(velocity);
}
