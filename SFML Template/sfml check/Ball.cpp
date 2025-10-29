#include "Ball.h"

const float Ball::ballRadius = 8.f;

Ball::Ball()
{
    ballShape.setRadius(ballRadius);
    ballShape.setFillColor(sf::Color::White);
    ballShape.setOrigin(ballRadius, ballRadius);
    collected = false;
}

Ball::~Ball()
{
}

void Ball::SetPosition(float x, float y)
{
    ballShape.setPosition(x, y);
}

void Ball::Draw(sf::RenderWindow& window)
{
    if (!collected)
    {
        window.draw(ballShape);
    }
}

bool Ball::CheckCollision(const sf::CircleShape& player)
{
    if (collected) return false;

    sf::Vector2f ballPos = ballShape.getPosition();
    sf::Vector2f playerPos = player.getPosition();
    float distance = std::sqrt(std::pow(ballPos.x - playerPos.x, 2) + std::pow(ballPos.y - playerPos.y, 2));

    return distance < (ballRadius + player.getRadius());
}

bool Ball::IsCollected() const
{
    return collected;
}

void Ball::Collect()
{
    collected = true;
}

void Ball::Reset()
{
    collected = false;
}

sf::Vector2f Ball::GetPosition() const
{
    return ballShape.getPosition();
}

bool Ball::CheckAllCollected(const std::vector<Ball>& balls)
{
    for (const auto& ball : balls) {
        if (!ball.IsCollected()) {
            return false;
        }
    }
    return true;
}