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
    CreateWall(walls, 0, 0, borderThickness, windowHeight);
    CreateWall(walls, 0, 0, windowWidth, borderThickness);
    CreateWall(walls, windowWidth - borderThickness, 0, borderThickness, windowHeight);
    CreateWall(walls, 0, windowHeight - borderThickness, windowWidth, borderThickness);

    for (int i = 0; i < 4; i++) {
        isMovingPlatform.push_back(false);
        platformSpeed.push_back(0);
        platformMinX.push_back(0);
        platformMaxX.push_back(0);
    }

    // MAZE WALLS
    std::vector<std::vector<float>> horizontalWalls = {
        {80, 80, 160}, {320, 80, 160}, {560, 80, 160},
        {0, 160, 80}, {400, 160, 400},
        {0, 240, 160}, {320, 240, 160}, {640, 240, 160},
        {160, 320, 80}, {480, 320, 80},
        {0, 400, 80}, {240, 400, 160}, {560, 400, 240},
        {160, 480, 80}, {480, 480, 80},
        {0, 560, 160}, {320, 560, 160}, {640, 560, 160},
        {10, 640, 440}, {250, 640, 480},
        {80, 720, 60}, {320, 720, 160}, {80, 720, 160}
    };

    std::vector<std::vector<float>> verticalWalls = {
        {80, 0, 80}, {80, 160, 80}, {80, 320, 80}, {80, 480, 80}, {80, 640, 80},
        {160, 80, 80}, {160, 400, 80}, {160, 640, 80},
        {240, 160, 80}, {240, 400, 80}, {240, 640, 80},
        {320, 80, 80}, {320, 400, 80}, {320, 640, 80},
        {400, 160, 80}, {400, 400, 80}, {400, 640, 80},
        {480, 80, 80}, {480, 400, 80}, {480, 640, 80},
        {560, 160, 80}, {560, 400, 80}, {560, 640, 80},
        {640, 80, 80}, {640, 400, 80}, {640, 700, 100},
        {720, 0, 80}, {720, 160, 80}, {720, 320, 80}, {720, 480, 80}, {720, 640, 80}
    };

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

    // MOVING PLATFORMS
    int movingPlatform1 = walls.size();
    CreateWall(walls, 100, 320, 120, borderThickness);
    isMovingPlatform.push_back(true);
    platformSpeed.push_back(0.4f);
    platformMinX.push_back(60);
    platformMaxX.push_back(800);

    int movingPlatform2 = walls.size();
    CreateWall(walls, 500, 480, 120, borderThickness);
    isMovingPlatform.push_back(true);
    platformSpeed.push_back(-0.5f);
    platformMinX.push_back(80);
    platformMaxX.push_back(600);

    int movingPlatform3 = walls.size();
    CreateWall(walls, 200, 560, 120, borderThickness);
    isMovingPlatform.push_back(true);
    platformSpeed.push_back(0.3f);
    platformMinX.push_back(60);
    platformMaxX.push_back(800);

    // INITIALIZE GAME OBJECTS
    std::vector<Ball> balls;

    // Initialize balls directly
    balls.resize(5);
    balls[0].SetPosition(120, 120);
    balls[1].SetPosition(400, 120);
    balls[2].SetPosition(650, 200);
    balls[3].SetPosition(120, 400);
    balls[4].SetPosition(650, 600);

    Score score;
    score.SetPosition(10, 10);
    score.UpdateFromBalls(balls);

    Image victoryImage;
    bool showVictory = false;
    victoryImage.LoadFromFile("C:/Users/semvh/Downloads/winLoL.png");
    float imageX = (windowWidth - victoryImage.GetWidth()) / 2;
    float imageY = (windowHeight - victoryImage.GetHeight()) / 2;
    victoryImage.SetPosition(imageX, imageY);

    player.SetPosition(40, 700);

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
                Player newPlayer;
                player = newPlayer;
                player.SetPosition(40, 700);

                // Reset balls directly
                balls.clear();
                balls.resize(5);
                balls[0].SetPosition(120, 120);
                balls[1].SetPosition(400, 120);
                balls[2].SetPosition(650, 200);
                balls[3].SetPosition(120, 400);
                balls[4].SetPosition(650, 600);

                score.UpdateFromBalls(balls);
                showVictory = false;
            }

            // Exit game when Q pressed and win screen is active
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q && showVictory) {
                window.close();
                return; // Exit the Update function and game
            }
        }

        // Update moving platforms
        for (int i = 0; i < walls.size(); i++) {
            if (isMovingPlatform[i]) {
                sf::Vector2f currentPos = walls[i].getPosition();
                float newX = currentPos.x + platformSpeed[i];
                if (newX <= platformMinX[i] || newX + walls[i].getSize().x >= platformMaxX[i]) {
                    platformSpeed[i] = -platformSpeed[i];
                    newX = currentPos.x + platformSpeed[i];
                }
                walls[i].setPosition(newX, currentPos.y);
            }
        }

        player.Movement();

        // Check wall collisions
        for (auto& wall : walls) {
            player.CheckCollision(wall);
        }

        // Check ball collisions
        for (auto& ball : balls) {
            if (!ball.IsCollected() && ball.CheckCollision(player.GetPacman())) {
                ball.Collect();
                score.UpdateFromBalls(balls);
            }
        }

        // Check victory
        if (Ball::CheckAllCollected(balls) && !showVictory) {
            showVictory = true;
            std::cout << "Victory! Press Q to exit the game." << std::endl;
        }

        // Rendering
        window.clear(sf::Color::Black);

        // Draw walls
        for (auto& wall : walls) window.draw(wall);

        // Draw balls
        for (auto& ball : balls) {
            ball.Draw(window);
        }

        // Draw player
        if (player.GetIsAlive()) {
            window.draw(player.GetPacman());
        }

        // Draw score
        score.Draw(window);

        // Draw victory
        if (showVictory) {
            victoryImage.Draw(window);
        }

        window.display();
    }
}