#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//�����, ����������� ���������

class Platforms : public Entity {
public:

	/*
	 * �����������.
	 * @param texture  ����������� ���������
	 * @param Name ���
	 * @param X ��������� ���������� �� ��� �
	 * @param Y ��������� ���������� �� ��� �
	 * @param W ����� ���������
	 * @param H ������ ���������
	 */

	Platforms(sf::Texture * texture, std::string Name, float X, float Y, float W, float H) : Entity(texture, Name, X, Y, W, H) {
		
	}


	/*
	 * �������, ����������� �������� ��������. ��������� ����������.
	 */

	void Move()
	{

	}
};