#include "Image.h"

Image::Image() {

}

Image::~Image() {

}

void Image::LoadFromFile(const std::string& filename) {
    if (!m_texture.loadFromFile(filename)) {
        m_texture.loadFromFile("winLoL.png");
    }
    m_sprite.setTexture(m_texture);
}

void Image::SetPosition(float x, float y) {
    m_sprite.setPosition(x, y);
}

void Image::Draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

float Image::GetWidth() const {
    return m_sprite.getGlobalBounds().width;
}

float Image::GetHeight() const {
    return m_sprite.getGlobalBounds().height;
}