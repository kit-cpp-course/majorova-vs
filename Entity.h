#pragma once

#include <SFML/Graphics.hpp>
//#include <iostream>


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

	Entity(sf::Texture * texture, std::string Name, float X, float Y);

	/*
	 * �����������.
	 * @param texture  ����������� ��������
	 * @param Name ���
	 * @param X ��������� ���������� �� ��� �
	 * @param Y ��������� ���������� �� ��� �
	 * @param W ������ ��������
	 * @param H ������ ��������
	 */

	Entity(sf::Texture * texture, std::string Name, float X, float Y, float W, float H);


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