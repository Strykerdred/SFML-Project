#include "Player.h"
#include "Collision.h"


Player::Player()
{
    pacman.setRadius(20.f);
    pacman.setFillColor(sf::Color::Yellow);
    pacman.setPosition(100, 100);
    pacman.setOrigin(pacman.getRadius(), pacman.getRadius());
}

Player::~Player()
{
}

void Player::Movement(const sf::RenderWindow& window)
{
    sf::Vector2f velocity(0.f, 0.f);
    if (!pacmanDead) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    velocity.y = -4.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  velocity.y = 4.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  velocity.x = -4.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x = 4.f;

        move(velocity, window);
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

void Player::move(const sf::Vector2f& direction, const sf::RenderWindow& window)
{
    pacman.move(direction);
    Collision::KeepCircleInBounds(pacman, window);
}

bool pacmanDead = false;
sf::CircleShape pacman;
