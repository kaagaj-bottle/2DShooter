#include "Obstacles.h"

Obstacles::Obstacles(int index,const std::string& filename)
{

    loadEntity(filename);
    setPos(400.f,400.f);
    setCentreToOrigin();
    setPos(screenWidth-50,(index*100)+50);
}

void Obstacles::update(int level)
{
    dynamics(sf::Vector2f(-1.f*level,0));
}

bool Obstacles::checkBulletCollision(Bullet* bullet)
{
    return this->getObjectRect().intersects(bullet->getObjectRect());
}

bool Obstacles::checkHeroCollision(HeroAircraft* hero)
{
    return this->getObjectRect().intersects(hero->getObjectRect());
}
Obstacles::~Obstacles()
{
    //dtor
}
