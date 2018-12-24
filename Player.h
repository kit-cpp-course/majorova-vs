#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Game;
//�����, ����������� ������

class Player : public Entity {
public:
	friend Game;

	/*
	 * �����������. 
	 * @param texture  ����������� ������
	 * @param Name ���
	 * @param X ��������� ���������� �� ��� �
	 * @param Y ��������� ���������� �� ��� �
	 */

	Player(sf::Texture * texture, std::string Name, float X, float Y ) : Entity(texture,  Name, X, Y){
		
	}

    /*
	 * �������, ����������� �������� ������. ��� ������� ������ "Left" � "Right" �� ���������� �������� �������������
	 * ����� � ������ ��������������. ����� ��������� ��������� � ��������.
	 */

	void Move() {
		const float moveSpeed = 3;
		dy += 0.2;
		body.move({ 0, dy });
		if (body.getPosition().y > 480) {
			dy = -10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			body.move({ -moveSpeed, 0 });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			body.move({ moveSpeed, 0 });

		if (body.getPosition().x < -100) body.setPosition({ 390, body.getPosition().y });
		if (body.getPosition().x > 390) body.setPosition({ -100, body.getPosition().y });
	}
	
private:
	float  h = 200; // ���������� ���������� �� ��� Y
	int Score; // ���� ������
};