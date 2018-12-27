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

	void Move() {
		
		if (name == "EasyEnemy") //Логика движения для врага с именем "EasyEnemy"
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