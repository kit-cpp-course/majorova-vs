#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"

//Абстрактный класс. Описывает все предметы, которые будут появляться в игре (игрок, платформы и т.д.)
class Entity {
public:
	
	float dx = 0, dy = 0; // Скорость движения по оси Х и У соответственно
	float x , y ; // Координаты 
	bool alive; 
	std::string name; // Имя сущности
	sf::RectangleShape body; // Прямоугольная форма. Основа для текстуры

	/*
	 * Конструктор.
	 * @param texture  Изображение сущности
	 * @param Name Имя
	 * @param X Начальная координата по оси Х
	 * @param Y Начальная координата по оси У
	 */

	Entity(sf::Texture * texture, std::string Name, float X, float Y) {
		body.setSize(sf::Vector2f(85.0f, 85.0f));
		body.setPosition({ X, Y });
		body.setTexture(texture);
		name = Name;
		alive = true;
	}

	/*
	 * Конструктор.
	 * @param texture  Изображение сущности
	 * @param Name Имя
	 * @param X Начальная координата по оси Х
	 * @param Y Начальная координата по оси У
	 * @param W Ширина картинки
	 * @param H Высота картинки
	 */

	Entity(sf::Texture * texture, std::string Name, float X, float Y, float W, float H) {
		body.setSize(sf::Vector2f(W, H));
		body.setPosition({ X, Y });
		body.setTexture(texture);
		name = Name;
		alive = true;
	}

	/*
	 * Виртуальная функция, описывающая движение предмета/игрока по окну
	 */
	
	virtual void Move() = 0;

	/*
	 * Функция, рисующая игрока/предметы.
	 * @param window  Окно, в котором рисуется изображение.
	 */

	void Draw(sf::RenderWindow & window) {
		window.draw(body);
	}
};