#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Game::Game() {
    isRunning = true;
}
Game::~Game() {


}
bool Game::GetIsRunning() {
	return isRunning;

}
void Game::Update() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::RectangleShape square(sf::Vector2f(640, 480));
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(50.f);
    square.setFillColor(sf::Color::Blue);
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(square);
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }

    
}