#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();
    ~Player();

    void Movement();
    void CheckCollision(const sf::RectangleShape& wall);
    bool GetIsAlive();
    sf::CircleShape& GetPacman();
    void SetPosition(float x, float y);

private:
    sf::CircleShape pacman;
    bool pacmanDead = false;
};