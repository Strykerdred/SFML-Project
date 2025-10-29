#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Ball.h"

class Score
{
public:
    Score();
    ~Score();

    void LoadFont(const std::string& fontPath);
    void UpdateScore(int collectedBalls, int totalBalls);
    void Draw(sf::RenderWindow& window);
    void SetPosition(float x, float y);

    // Method to update score based on balls
    void UpdateFromBalls(const std::vector<Ball>& balls);

private:
    int collectedBalls;
    int totalBalls;
    sf::Text scoreText;
    sf::Font font;
    bool fontLoaded;
};