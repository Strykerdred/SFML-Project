#include "Image.h"

Image::Image() {

}

Image::~Image() {

}

void Image::LoadFromFile(const std::string& filename) {
    if (!m_texture.loadFromFile(filename)) {
        m_texture.loadFromFile("error.png");
    }
    m_sprite.setTexture(m_texture);
}

