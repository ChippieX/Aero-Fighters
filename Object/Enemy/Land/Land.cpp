#include "Land.h"

Land::Land(short id, bool left, float* backgroundSpeed, sf::Vector2u winSize, std::vector<Object*>* objects,
	sf::Vector2f pos, sf::Vector2f vel) : Enemy(id, left, pos, vel)
{
	type = LAND;

	this->backgroundSpeed = backgroundSpeed;

	setSize(15, 25);

	switch (id)
	{
	case 0: //Weak Tank
		health = 1;
		break;
	case 1: //STRONG Tank
		health = 7;
		break;
	case 2: //fort building
		health = 60;
		setSize(60, 60);
		break;
	}

	sprite.setSize(size);
	sprite.setOrigin(size / 2.f);
	setRandColor();
}

void Land::update(sf::Vector2u winSize, std::vector<Object*>* objects)
{
	enemyUpdate(winSize, objects);

	setPos(getPos().x, getPos().y + *backgroundSpeed);
}