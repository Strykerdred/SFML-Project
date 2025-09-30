#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"

class MyShape : public sf::Drawable {
public:
    MyShape();
    void setPosition(float x, float y);
    void setColor(const sf::Color& color);
    void setRadius(float radius);

    bool collidesWith(const MyShape& other) const;
    void keepInBounds(const sf::RenderWindow& window);

    const sf::CircleShape& getShape() const;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::CircleShape shape;
};