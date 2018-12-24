#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"

//����������� �����. ��������� ��� ��������, ������� ����� ���������� � ���� (�����, ��������� � �.�.)
class Entity {
public:
	
	float dx = 0, dy = 0; // �������� �������� �� ��� � � � ��������������
	float x , y ; // ���������� 
	bool alive; 
	std::string name; // ��� ��������
	sf::RectangleShape body; // ������������� �����. ������ ��� ��������

	/*
	 * �����������.
	 * @param texture  ����������� ��������
	 * @param Name ���
	 * @param X ��������� ���������� �� ��� �
	 * @param Y ��������� ���������� �� ��� �
	 */

	Entity(sf::Texture * texture, std::string Name, float X, float Y) {
		body.setSize(sf::Vector2f(85.0f, 85.0f));
		body.setPosition({ X, Y });
		body.setTexture(texture);
		name = Name;
		alive = true;
	}

	/*
	 * �����������.
	 * @param texture  ����������� ��������
	 * @param Name ���
	 * @param X ��������� ���������� �� ��� �
	 * @param Y ��������� ���������� �� ��� �
	 * @param W ������ ��������
	 * @param H ������ ��������
	 */

	Entity(sf::Texture * texture, std::string Name, float X, float Y, float W, float H) {
		body.setSize(sf::Vector2f(W, H));
		body.setPosition({ X, Y });
		body.setTexture(texture);
		name = Name;
		alive = true;
	}

	/*
	 * ����������� �������, ����������� �������� ��������/������ �� ����
	 */
	
	virtual void Move() = 0;

	/*
	 * �������, �������� ������/��������.
	 * @param window  ����, � ������� �������� �����������.
	 */

	void Draw(sf::RenderWindow & window) {
		window.draw(body);
	}
};