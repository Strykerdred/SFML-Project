#include "Score.h"
#include <iostream>

Score::Score() : collectedBalls(0), totalBalls(0), fontLoaded(false)
{
    // Load Windows system font
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Failed to load Arial font!" << std::endl;
    }
    else {
        fontLoaded = true;
        scoreText.setFont(font);
        std::cout << "Arial font loaded successfully!" << std::endl;
    }

    scoreText.setString("Score: 0/0");
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setStyle(sf::Text::Bold);
}

Score::~Score()
{
}

void Score::LoadFont(const std::string& fontPath)
{
    if (font.loadFromFile(fontPath))
    {
        scoreText.setFont(font);
        fontLoaded = true;
        std::cout << "Font loaded successfully: " << fontPath << std::endl;
    }
    else
    {
        std::cerr << "Failed to load font: " << fontPath << std::endl;
        fontLoaded = false;
    }
}

void Score::UpdateScore(int collected, int total)
{
    collectedBalls = collected;
    totalBalls = total;
    scoreText.setString("Score: " + std::to_string(collectedBalls) + "/" + std::to_string(totalBalls));
}

void Score::UpdateFromBalls(const std::vector<Ball>& balls)
{
    collectedBalls = 0;
    totalBalls = balls.size();

    for (const auto& ball : balls) {
        if (ball.IsCollected()) {
            collectedBalls++;
        }
    }

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