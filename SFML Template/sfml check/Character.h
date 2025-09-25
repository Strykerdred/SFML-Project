#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Character : public sf::Drawable
{
public:
	Character();
	~Character();

	void MoveTo(float x, float y);
	void Update(float dt);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}
	
private:

    int health;
	std::string name;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::VertexArray m_vertices;
};

