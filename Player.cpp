#include "Player.h"


void Player::Move()
{
	const float moveSpeed = 3;
	dy += 0.2;
	body.move({ 0, dy });
	if (body.getPosition().y > 480) 
	{
		dy = -10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		body.move({ -moveSpeed, 0 });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		body.move({ moveSpeed, 0 });
	}

	if (body.getPosition().x < -100)
	{
		body.setPosition({ 390, body.getPosition().y });
	}
	if (body.getPosition().x > 390)
	{
		body.setPosition({ -100, body.getPosition().y });
	}
}
