#include "Player.h"


Player::Player()
{
    pacman.setRadius(20.f);
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    velocity.y = -4.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  velocity.y = 4.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  velocity.x = -4.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x = 4.f;

        pacman.move(velocity);

    }
}

bool Player::GetIsAlive()
{
    return !pacmanDead;
}

void Player::Collision(Enemy& anEnemy)
{
    // checking for collision
    if (pacman.getGlobalBounds().intersects(anEnemy.GetShape().getGlobalBounds())) {
        std::cout << "Pac-Man died!" << std::endl;
        pacmanDead = true;
    }
}

sf::CircleShape Player::GetShape()
{
    return pacman;
}
