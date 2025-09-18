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

    sf::RectangleShape square(sf::Vector2f(50, 480));
    sf::RectangleShape square2(sf::Vector2f(640, 50));
    sf::RectangleShape square3(sf::Vector2f(50, 1080));
    sf::CircleShape shape(25.f);
    sf::CircleShape shape2(25.f);
    square.setFillColor(sf::Color::Red);
    square2.setFillColor(sf::Color::Red);
    square3.setFillColor(sf::Color::Red);
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
        window.draw(square2);
        window.draw(square3);
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }

    
}