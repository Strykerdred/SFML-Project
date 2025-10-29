#include "Score.h"
#include <iostream>

Score::Score() : collectedBalls(0), totalBalls(0)
{
    // Try to load common system fonts
#ifdef _WIN32
    // Windows paths
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        if (!font.loadFromFile("C:/Windows/Fonts/tahoma.ttf")) {
            std::cout << "ERROR: Could not load system font!" << std::endl;
            return;
        }
    }

#endif

    scoreText.setFont(font);
    scoreText.setString("Score: 0/0");
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setStyle(sf::Text::Bold);
}

Score::~Score()
{
}

void Score::UpdateScore(int collected, int total)
{
    collectedBalls = collected;
    totalBalls = total;
    scoreText.setString("Score: " + std::to_string(collectedBalls) + "/" + std::to_string(totalBalls));
}

void Score::Draw(sf::RenderWindow& window)
{
    window.draw(scoreText);
}

void Score::SetPosition(float x, float y)
{
    scoreText.setPosition(x, y);
}