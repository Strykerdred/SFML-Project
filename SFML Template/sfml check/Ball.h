#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

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
    void Reset(); // Reset ball state
    sf::Vector2f GetPosition() const;

    // Static method to check if all balls are collected
    static bool CheckAllCollected(const std::vector<Ball>& balls);

private:
    sf::CircleShape ballShape;
    bool collected;
    static const float ballRadius;
};