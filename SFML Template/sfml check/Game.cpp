#include "Game.h"



Game::Game()
{
	isRunning = true;
}
Game::~Game()
{

}
bool Game::getIsRunning()
{
	return isRunning;
}
void Game::Update()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    window.setFramerateLimit(60);

    // Enemy lineup
    sf::CircleShape Evil(20.f);

	Player player;
	Enemy enemy;

    

    // holy shit fuck fonts
    sf::Font font;
    if (!font.loadFromFile("Assets/comic.ttf")) {
        std::cout << "Error loading system font!" << std::endl;
    }
    else {
        std::cout << "Font loaded successfully!" << std::endl;
    }

    sf::Text gameOver("GAME OVER", font, 50);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setPosition(150, 200);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
	    player.Movement();
        player.Collision(enemy);



		// Rendering
        window.clear(sf::Color::Black);
        window.draw(enemy.GetShape());

        if (player.GetIsAlive()) {
            window.draw(player.GetShape());
        }
        else {
            window.draw(gameOver);
        }
        

        window.display();
    }
}