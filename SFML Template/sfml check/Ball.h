#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball();
    ~Ball();

    void SetPosition(float x, float y);
    void Draw(sf::RenderWindow& window);
    bool CheckCollision(const sf::CircleShape& player);
    bool IsCollected() const;
    void Collect();
    sf::Vector2f GetPosition() const;

private:
    sf::CircleShape ballShape;
    bool collected;
    static const float ballRadius;
};