#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

// Класс, описывающий "врага"

class Enemy : public Entity {
public:
	/*
	 * Конструктор.
	 * @param texture  Изображение монстра
	 * @param Name Имя
	 * @param X Начальная координата по оси Х
	 * @param Y Начальная координата по оси У
	 */

	Enemy(sf::Texture * texture, std::string Name, float X, float Y) : Entity(texture, Name, X, Y) {

	}

	/*
         * Функция, описывающая движение врага. Движение происходит по горизонтали
         */

	void Move();
};
