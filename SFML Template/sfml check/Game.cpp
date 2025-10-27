#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "Score.h"
#include "Image.h"

Game::Game() : window(sf::VideoMode(800, 800), "Pacman Maze Game")
{
    isRunning = true;
}

Game::~Game() {
}

bool Game::GetIsRunning() {
    return isRunning;
}

void Game::CreateWall(std::vector<sf::RectangleShape>& walls, float x, float y, float width, float height, sf::Color color = sf::Color::Red)
{
    sf::RectangleShape wall(sf::Vector2f(width, height));
    wall.setPosition(x, y);
    wall.setFillColor(color);
    walls.push_back(wall);
}

void Game::Update() {

    const float windowWidth = 800;
    const float windowHeight = 800;
    const float borderThickness = 16;

    std::vector<sf::RectangleShape> walls;
    std::vector<bool> isMovingPlatform;
    std::vector<float> platformSpeed;
    std::vector<float> platformMinX;
    std::vector<float> platformMaxX;

    // Create border walls
    CreateWall(walls, 0, 0, borderThickness, windowHeight); // left
    CreateWall(walls, 0, 0, windowWidth, borderThickness); // top
    CreateWall(walls, windowWidth - borderThickness, 0, borderThickness, windowHeight); // right
    CreateWall(walls, 0, windowHeight - borderThickness, windowWidth, borderThickness); // bottom

    // Add stationary flags for borders
    for (int i = 0; i < 4; i++) {
        isMovingPlatform.push_back(false);
        platformSpeed.push_back(0);
        platformMinX.push_back(0);
        platformMaxX.push_back(0);
    }

    // MAZE WALLS - Connected to borders
    std::vector<std::vector<float>> horizontalWalls = {
        // Top section
        {80, 80, 160}, {320, 80, 160}, {560, 80, 160},

        // Upper middle
        {0, 160, 80}, {400, 160, 400},
        {0, 240, 160}, {320, 240, 160}, {640, 240, 160},

        // Center
        {160, 320, 80}, {480, 320, 80},
        {0, 400, 80}, {240, 400, 160}, {560, 400, 240},

        // Lower middle
        {160, 480, 80}, {480, 480, 80},
        {0, 560, 160}, {320, 560, 160}, {640, 560, 160},

        // Bottom section
        {80, 640, 240}, {400, 640, 320},
        {80, 720, 160}, {320, 720, 160}, {560, 720, 160}
    };

    std::vector<std::vector<float>> verticalWalls = {
        // Left side
        {80, 0, 80}, {80, 160, 80}, {80, 320, 80}, {80, 480, 80}, {80, 640, 80},

        // Left middle
        {160, 80, 80}, {160, 400, 80}, {160, 640, 80},
        {240, 160, 80}, {240, 400, 80}, {240, 640, 80},

        // Center columns
        {320, 80, 80}, {320, 400, 80}, {320, 640, 80},
        {400, 160, 80}, {400, 400, 80}, {400, 640, 80},

        // Right middle
        {480, 80, 80}, {480, 400, 80}, {480, 640, 80},
        {560, 160, 80}, {560, 400, 80}, {560, 640, 80},

        // Right side
        {640, 80, 80}, {640, 400, 80}, {640, 640, 80},
        {720, 0, 80}, {720, 160, 80}, {720, 320, 80}, {720, 480, 80}, {720, 640, 80}
    };

    // Create all stationary walls
    for (auto& wall : horizontalWalls) {
        CreateWall(walls, wall[0], wall[1], wall[2], borderThickness);
        isMovingPlatform.push_back(false);
        platformSpeed.push_back(0);
        platformMinX.push_back(0);
        platformMaxX.push_back(0);
    }
    for (auto& wall : verticalWalls) {
        CreateWall(walls, wall[0], wall[1], borderThickness, wall[2]);
        isMovingPlatform.push_back(false);
        platformSpeed.push_back(0);
        platformMinX.push_back(0);
        platformMaxX.push_back(0);
    }

    // ADD MOVING PLATFORMS - SLOWER AND LONGER RANGE
    int movingPlatform1 = walls.size();
    CreateWall(walls, 100, 320, 120, borderThickness);
    isMovingPlatform.push_back(true);
    platformSpeed.push_back(0.4f); // SLOWER speed
    platformMinX.push_back(60);    // WIDER left boundary
    platformMaxX.push_back(800);   // WIDER right boundary

    int movingPlatform2 = walls.size();
    CreateWall(walls, 500, 480, 120, borderThickness);
    isMovingPlatform.push_back(true);
    platformSpeed.push_back(-0.5f); // SLOWER speed (negative = left direction)
    platformMinX.push_back(80);     // WIDER left boundary
    platformMaxX.push_back(600);    // WIDER right boundary

    int movingPlatform3 = walls.size();
    CreateWall(walls, 200, 560, 120, borderThickness);
    isMovingPlatform.push_back(true);
    platformSpeed.push_back(0.3f); // SLOWER speed
    platformMinX.push_back(60);    // WIDER left boundary
    platformMaxX.push_back(800);   // WIDER right boundary

    // Create balls
    std::vector<Ball> balls;
    balls.resize(5);

    // Ball positions - adjusted to avoid moving platforms
    balls[0].SetPosition(120, 120);   // Top-left
    balls[1].SetPosition(400, 120);   // Top-center   
    balls[2].SetPosition(650, 200);   // Top-right 
    balls[3].SetPosition(120, 400);   // Middle-left
    balls[4].SetPosition(650, 600);   // Bottom-right 

    // Initialize score
    Score score;
    const int totalBalls = balls.size();
    score.SetPosition(10, 10);
    int collectedBalls = 0;
    score.UpdateScore(collectedBalls, totalBalls);

    // Victory image using your Image class
    Image victoryImage;
    bool showVictory = false;

    // Load victory image - UPDATE THE PATH TO YOUR winLoL.png FILE
    victoryImage.LoadFromFile("C:/Users/semvh/Downloads/winLoL.png");

    // Center the image on screen using the new GetWidth/GetHeight methods
    float imageX = (windowWidth - victoryImage.GetWidth()) / 2;
    float imageY = (windowHeight - victoryImage.GetHeight()) / 2;
    victoryImage.SetPosition(imageX, imageY);

    // Set player spawn position
    player.SetPosition(40, 640);

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Restart game when R pressed and player dead
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && !player.GetIsAlive()) {
                // Reset player
                Player newPlayer;
                player = newPlayer;
                player.SetPosition(40, 640);

                // Reset balls
                balls.clear();
                balls.resize(5);
                balls[0].SetPosition(120, 120);
                balls[1].SetPosition(400, 120);
                balls[2].SetPosition(650, 200);
                balls[3].SetPosition(120, 400);
                balls[4].SetPosition(650, 600);

                // Reset score and victory
                collectedBalls = 0;
                showVictory = false;
                score.UpdateScore(collectedBalls, totalBalls);
            }
        }

        // UPDATE MOVING PLATFORMS
        for (int i = 0; i < walls.size(); i++) {
            if (isMovingPlatform[i]) {
                // Move the platform
                sf::Vector2f currentPos = walls[i].getPosition();
                float newX = currentPos.x + platformSpeed[i];

                // Reverse direction if hitting boundaries
                if (newX <= platformMinX[i] || newX + walls[i].getSize().x >= platformMaxX[i]) {
                    platformSpeed[i] = -platformSpeed[i];
                    newX = currentPos.x + platformSpeed[i]; // Move in new direction
                }

                walls[i].setPosition(newX, currentPos.y);
            }
        }

        // Move player
        player.Movement();

        // Check wall collisions
        for (auto& wall : walls) {
            player.CheckCollision(wall);
        }

        // Check ball collisions & update score
        for (auto& ball : balls) {
            if (!ball.IsCollected() && ball.CheckCollision(player.GetPacman())) {
                ball.Collect();
                collectedBalls++;
                score.UpdateScore(collectedBalls, totalBalls);
            }
        }

        // Check if all balls are collected
        if (collectedBalls >= totalBalls && !showVictory) {
            showVictory = true;
            std::cout << "Victory! All balls collected!" << std::endl;
        }

        // Rendering
        window.clear(sf::Color::Black);

        // Draw walls
        for (auto& wall : walls) window.draw(wall);

        // Draw balls
        for (auto& ball : balls) {
            ball.Draw(window);
        }

        // Draw player if alive
        if (player.GetIsAlive()) {
            window.draw(player.GetPacman());
        }

        // Draw score
        score.Draw(window);

        // Draw victory image if all balls collected
        if (showVictory) {
            victoryImage.Draw(window);
        }

        window.display();
    }
}