#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"

Game::Game() : window(sf::VideoMode(800, 800), "CapNam Collects Big Balls")
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

    // Create solid borders (completely closed)
    CreateWall(walls, 0, 0, borderThickness, windowHeight); // left
    CreateWall(walls, 0, 0, windowWidth, borderThickness); // top
    CreateWall(walls, windowWidth - borderThickness, 0, borderThickness, windowHeight); // right
    CreateWall(walls, 0, windowHeight - borderThickness, windowWidth, borderThickness); // bottom

   // spawn area
    float spawnSize = 120;
    float spawnX = 60;
    float spawnY = windowHeight - spawnSize - 60;

    // Maze layout
    std::vector<std::vector<float>> horizontalWalls = {
        {160, 80, 480},
        {80, 160, 160}, {320, 160, 160},
        {160, 240, 80}, {400, 240, 80},
        {80, 320, 80}, {240, 320, 80}, {400, 320, 80}, {560, 320, 80},
        {240, 400, 80}, {480, 400, 80},
        {80, 480, 160}, {320, 480, 160},
        {240, 560, 80}, {480, 560, 80},
        {160, 640, 80}, {400, 640, 80},
        {80, 720, 80}, {240, 720, 160}, {560, 720, 80},
        {640, 160, 80}, {640, 400, 80}, {640, 640, 80}
    };

    std::vector<std::vector<float>> verticalWalls = {
        {80, 10, 170}, {80, 240, 80}, {80, 300, 180}, {80, 560, 80},
        {160, 80, 80}, {160, 320, 80}, {160, 480, 80}, {160, 640, 80},
        {240, 160, 80}, {240, 400, 80}, {240, 560, 80},
        {320, 80, 80}, {320, 240, 80}, {320, 400, 80}, {320, 560, 80},
        {400, 160, 80}, {400, 320, 80}, {400, 480, 80}, {400, 640, 80},
        {480, 80, 80}, {480, 240, 80}, {480, 400, 80}, {480, 560, 80},
        {560, 160, 80}, {560, 320, 80}, {560, 480, 80}, {560, 640, 80},
        {640, 80, 80}, {640, 240, 80}, {640, 400, 80}, {640, 560, 80},
        {720, 160, 80}, {720, 320, 80}, {720, 480, 80}, {720, 640, 80}
    };

    // Create all walls
    for (auto& wall : horizontalWalls) {
        CreateWall(walls, wall[0], wall[1], wall[2], borderThickness);
    }
    for (auto& wall : verticalWalls) {
        CreateWall(walls, wall[0], wall[1], borderThickness, wall[2]);
    }

    // Create 5 balls at strategic positions in the maze
    std::vector<Ball> balls;
    balls.resize(5);

    // Set ball positions in open areas of the maze
    balls[0].SetPosition(120, 120);   // Top-left area
    balls[1].SetPosition(360, 200);   // Top-center area
    balls[2].SetPosition(680, 120);   // Top-right area
    balls[3].SetPosition(120, 400);   // Middle-left area
    balls[4].SetPosition(680, 680);   // Bottom-right area

    // Set player starting position
    float playerStartX = spawnX + 20;
    float playerStartY = spawnY + 20;
    player.SetPosition(playerStartX, playerStartY);

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && !player.GetIsAlive()) {
                // Reset game
                Player newPlayer;
                player = newPlayer;
                player.SetPosition(playerStartX, playerStartY);

                // Reset all balls
                for (auto& ball : balls) {
                    Ball newBall;
                    ball = newBall;
                }
                // Reset ball positions
                balls[0].SetPosition(120, 120);
                balls[1].SetPosition(360, 200);
                balls[2].SetPosition(680, 120);
                balls[3].SetPosition(120, 400);
                balls[4].SetPosition(680, 680);
            }
        }

        // Move player
        player.Movement();

        // Check collisions with walls
        for (auto& wall : walls) {
            player.CheckCollision(wall);
        }

        // Check collisions with balls
        for (auto& ball : balls) {
            if (!ball.IsCollected() && ball.CheckCollision(player.GetPacman())) {
                ball.Collect();
            }
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

        window.display();
    }
}