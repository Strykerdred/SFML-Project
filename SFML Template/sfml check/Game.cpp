#include "Game.h" //het heeft "" inplaats van <> omdat het een eigen bestand is.
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> //zorgt dat we de c:out kunnen gebruiken, de io staat voor input output.
Game::Game()
{
    isRunning = true;
}
Game::~Game() {


}
bool Game::GetIsRunning() {
	return isRunning;

}
void Game::Update() {

    const float windowWidth = 640;
    const float windowHeight = 480;
    const float borderThickness = 20;

    std::vector<sf::RectangleShape> walls;

    // Add borders
    sf::RectangleShape left(sf::Vector2f(borderThickness, windowHeight));
    left.setPosition(0, 0);
    left.setFillColor(sf::Color::Red);
    walls.push_back(left);

    sf::RectangleShape top(sf::Vector2f(windowWidth, borderThickness));
    top.setPosition(0, 0);
    top.setFillColor(sf::Color::Red);
    walls.push_back(top);

    sf::RectangleShape right(sf::Vector2f(borderThickness, windowHeight));
    right.setPosition(windowWidth - borderThickness, 0);
    right.setFillColor(sf::Color::Red);
    walls.push_back(right);

    sf::RectangleShape bottom(sf::Vector2f(windowWidth, borderThickness));
    bottom.setPosition(0, windowHeight - borderThickness);
    bottom.setFillColor(sf::Color::Red);
    walls.push_back(bottom);

    // Add more walls for a Pac-Man layout as needed
    // Example:
    sf::RectangleShape innerWall(sf::Vector2f(320, borderThickness));
    innerWall.setPosition(160, 100);
    innerWall.setFillColor(sf::Color::Red);
    walls.push_back(innerWall);

    sf::RectangleShape innerWall1(sf::Vector2f(320, borderThickness));
    innerWall1.setPosition(160, 200);
    innerWall1.setFillColor(sf::Color::Red);
    walls.push_back(innerWall1);

    sf::RectangleShape innerWall2(sf::Vector2f(200, borderThickness));
    innerWall2.setPosition(490, 300);
    innerWall2.setFillColor(sf::Color::Red);
    walls.push_back(innerWall2);


    sf::RectangleShape innerWall2b(sf::Vector2f(150, borderThickness));
    innerWall2b.setPosition(0, 300);
    innerWall2b.setFillColor(sf::Color::Red);
    walls.push_back(innerWall2b);

    sf::RectangleShape innerWall3(sf::Vector2f(320, borderThickness));
    innerWall3.setPosition(160, 375);
    innerWall3.setFillColor(sf::Color::Red);
    walls.push_back(innerWall3);

    sf::CircleShape shape(25.f);
    sf::CircleShape shape2(25.f);
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto& wall : walls)
            window.draw(wall);
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }
}