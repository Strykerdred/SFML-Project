#include "MyShape.h"
#include "Collision.h"

MyShape::MyShape() : shape(50.f) {
    shape.setFillColor(sf::Color::Green);
}

void MyShape::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void MyShape::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}

void MyShape::setRadius(float radius) {
    shape.setRadius(radius);
}

bool MyShape::collidesWith(const MyShape& other) const {
    return Collision::CircleCollision(this->shape, other.shape);
}

void MyShape::keepInBounds(const sf::RenderWindow& window) {
    Collision::KeepCircleInBounds(this->shape, window);
}

const sf::CircleShape& MyShape::getShape() const {
    return shape;
}

void MyShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

