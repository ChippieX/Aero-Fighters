#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "../Object/Enemy/Enemy.h"
#include "../Object/Projectile/Projectile.h"
#include "../Object/Collectable/Collectable.h"

class Level : public sf::Drawable
{
public:
	Level();

	void load(sf::Vector2u winSize, int mapId);

	void update(sf::Vector2u winSize);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<Enemy*> enemies;
	std::vector<Projectile*> projs;
	std::vector<Collectable*> collectables;

	sf::RectangleShape bg;
	sf::Texture bgImg;
	sf::IntRect rect;
	int bgSpeed = 1, bgDist = 0;
};

