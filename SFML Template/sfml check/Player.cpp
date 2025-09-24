#include "Player.h"


Player::Player()
{
    pacman.setRadius(10.f);
    pacman.setFillColor(sf::Color::Yellow);
    pacman.setPosition(100, 100);
}

Player::~Player()
{
}

void Player::Movement()
{
    sf::Vector2f velocity(0.f, 0.f);
    if (!pacmanDead) {
        velocity = { 0.f, 0.f };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    velocity.y = -0.2f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  velocity.y = 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  velocity.x = -0.2f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x = 0.2;

        pacman.move(velocity);

    }
}

bool Player::GetIsAlive() {
    return !pacmanDead;
}

sf::CircleShape Player::GetShape() {
    return pacman;
}