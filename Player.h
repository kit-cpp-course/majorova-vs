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

	Player(sf::Texture * texture, std::string Name, float X, float Y) : Entity(texture, Name, X, Y) {
		
	}

    /*
	 * �������, ����������� �������� ������. ��� ������� ������ "Left" � "Right" �� ���������� �������� �������������
	 * ����� � ������ ��������������. ����� ��������� ��������� � ��������.
	 */

	void Move();
	
private:
	float  h = 200; // ���������� ���������� �� ��� Y
	int score = 0; // ���� ������
};