#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::MoveTo(float x, float y)
{
}

void Character::Update(float dt)
{
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	    target.draw(m_sprite, states);
}