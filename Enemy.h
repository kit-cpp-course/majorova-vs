#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

// �����, ����������� "�����"

class Enemy : public Entity {
public:
	
	/*
	 * �����������.
	 * @param texture  ����������� �������
	 * @param Name ���
	 * @param X ��������� ���������� �� ��� �
	 * @param Y ��������� ���������� �� ��� �
	 */

	Enemy(sf::Texture * texture, std::string Name, float X, float Y) : Entity(texture, Name, X, Y) {

	}


	/*
     * �������, ����������� �������� �����. �������� ���������� �� �����������
     */

	void Move() {
		
		if (name == "EasyEnemy") //������ �������� ��� ����� � ������ "EasyEnemy"
		{
			dx = 2;
			body.move({ dx, 0 });
			if (body.getPosition().x < -100) body.setPosition({ 390, body.getPosition().y });
			if (body.getPosition().x > 390) body.setPosition({ -100, body.getPosition().y });
		}
		if (name == "EasyEnemy2") 
		{
			dx = 2;
			body.move({ -dx, 0 });
			if (body.getPosition().x < -100) body.setPosition({ 390, body.getPosition().y });
			if (body.getPosition().x > 390) body.setPosition({ -100, body.getPosition().y });
		}
	}	
};