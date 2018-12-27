#include "Enemy.h"

void Enemy::Move()
{
	if (name == "EasyEnemy") //Логика движения для врага с именем "EasyEnemy"
	{
		dx = 2;
		body.move({ dx, 0 });
		if (body.getPosition().x < -100)
		{
			body.setPosition({ 390, body.getPosition().y });
		}
		if (body.getPosition().x > 390)
		{
			body.setPosition({ -100, body.getPosition().y });
		}
	}
	if (name == "EasyEnemy2")
	{
		dx = 2;
		body.move({ -dx, 0 });
		if (body.getPosition().x < -100)
		{
			body.setPosition({ 390, body.getPosition().y });
		}
		if (body.getPosition().x > 390) 
		{
			body.setPosition({ -100, body.getPosition().y });
		}
	}
}
