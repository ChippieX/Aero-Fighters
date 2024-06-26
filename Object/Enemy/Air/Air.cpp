#include "Air.h"

Air::Air(short id, bool left, float* backgroundDist, int startMark, 
sf::Vector2u winSize, std::vector<Object*>* objects, sf::Vector2f pos, 
sf::Vector2f vel) : Enemy(id, left, sf::Vector2f(-100, -100), 
sf::Vector2f(0, 0))
{
	type = AIR;

	this->startMark = startMark;
	this->backgroundDist = backgroundDist;

	if (startMark == -1)
		entered = true;

	spawnPos = pos;
	spawnVel = vel;

	health = 1;
	setSize(32, 32);

	switch (id)
	{
	case 0: //baby copter
		setSpriteNum(0);
		setOrientation(8);
		chopperBlades = new Air(3, left, backgroundDist, startMark, winSize, 
		objects, pos, vel); //Creates the top
		objects->push_back(chopperBlades);
		break;
	case 3: //chopper blades
		setSpriteNum(19);
		health = 999;
		break;
	case 1: //big plane
		setSpriteNum(14);
		setSize(80, 80);
		health = 15;
		break;
	case 2: //spinny planes
		setSpriteNum(15);
		break;
	}

	sprite.setSize(size);
	sprite.setOrigin(size / 2.f);
}

void Air::update(sf::Vector2u winSize, std::vector<Object*>* objects, 
	bool time)
{
	//Do things here only if time is moving
	if(time != 0)
	{
		switch (id)
		{
			//ENGLAND
		case 0: //baby copter
			if (shouldDelete())
				chopperBlades->setDelete();
		case 3: //chopper blades
			if (entered)
			{
				vel.y *= 0.95;
			}
		}
	enemyUpdate(winSize, objects);	
	}
}