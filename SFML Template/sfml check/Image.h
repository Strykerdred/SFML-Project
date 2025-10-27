#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Image
{
public:
    Image();
    ~Image();
    void LoadFromFile(const std::string& filename);
    void SetPosition(float x, float y);
    void Draw(sf::RenderWindow& window);
    float GetWidth() const;
    float GetHeight() const;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};