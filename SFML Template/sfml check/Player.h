#include <SFML/Graphics.hpp>
#include <iostream>


#pragma once
class Player
{
public:
    Player();
    ~Player();
    void Movement();
    bool GetIsAlive();


    sf::CircleShape GetShape();
    sf::CircleShape& GetPacman() { return pacman; }

private:
    bool pacmanDead = false;
    sf::CircleShape pacman;

protected:



};