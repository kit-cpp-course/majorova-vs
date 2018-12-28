#include "Entity.h"

Entity::Entity(sf::Texture * texture, std::string Name, float X, float Y)
{
	body.setSize(sf::Vector2f(85.0f, 85.0f));
	body.setPosition({ X, Y });
	body.setTexture(texture);
	name = Name;
}

Entity::Entity(sf::Texture * texture, std::string Name, float X, float Y, float W, float H)
{
	body.setSize(sf::Vector2f(W, H));
	body.setPosition({ X, Y });
	body.setTexture(texture);
	name = Name;
}
