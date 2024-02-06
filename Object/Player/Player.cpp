#include "Player.h"

Player::Player()
{
	size = sf::Vector2f(25, 50);
	sprite = sf::RectangleShape(size);
	sprite.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	sprite.setOrigin(size / 2.f);
}

Player::Player(sf::Vector2f position)
{
	pos = position;
	sprite.setPosition(pos);
}

int Player::getScore() const
{
	return score;
}

int Player::getLives() const
{
	return lives;
}

bool Player::isAlive() const
{
	return alive;
}

void Player::move(sf::Vector2f offset, sf::Vector2u winSize)
{
	pos += offset * speed;

	if (pos.x - size.x / 2.f < 0)
		pos.x = size.x / 2.f;
	else if (pos.x + size.x / 2.f > winSize.x)
		pos.x = winSize.x - size.x / 2.f;

	if (pos.y - size.y / 2.f < 0)
		pos.y = size.y / 2.f;
	else if (pos.y + size.y / 2.f > winSize.y)
		pos.y = winSize.y - size.y / 2.f;

	sprite.setPosition(pos);
}

void Player::setPos(sf::Vector2f newPos)
{
	pos = newPos;
}

void Player::shoot(std::vector<Projectile*>& proj)
{
	// The cooldown is needed, otherwise it shoots a constant stream
	if (!shootCoolDown)
	{
		proj.push_back(new StraightProjectile(pos, 15.f, 15.f));
		proj.push_back(new StraightProjectile(pos, 0.f, 15.f));
		proj.push_back(new StraightProjectile(pos, -15.f, 15.f));
		shootCoolDown = shootCoolDownVal;
	}
}

void Player::update()
{
	if (shootCoolDown)
		shootCoolDown--;
}
