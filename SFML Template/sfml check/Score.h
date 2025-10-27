#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Score
{
public:
    Score();
    ~Score();
    void UpdateScore(int collectedBalls, int totalBalls);
    void Draw(sf::RenderWindow& window);
    void SetPosition(float x, float y);

private:
    int collectedBalls;
    int totalBalls;
    sf::Text scoreText;
    sf::Font font;
};