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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  velocity.y = 0.2f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  velocity.x = -0.2f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x = 0.2f;

        pacman.move(velocity);
    }
}

void Player::CheckCollision(const sf::RectangleShape& wall)
{
    if (!pacmanDead && pacman.getGlobalBounds().intersects(wall.getGlobalBounds()))
    {
        pacmanDead = true;
        pacman.setFillColor(sf::Color::Transparent); // Make invisible when dead
    }
}

bool Player::GetIsAlive() {
    return !pacmanDead;
}

sf::CircleShape& Player::GetPacman() {
    return pacman;
}

void Player::SetPosition(float x, float y) {
    pacman.setPosition(x, y);
}