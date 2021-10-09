#include "Bullet.h"

Bullet::Bullet(const std::string& textureName)
{
    loadEntity(textureName);
    setCentre(bulletWidth/2,bulletHeight/2);
    setVelocity(2.f,0.f);
}

void Bullet::update(HeroAircraft& heroAircraft)
{

    setPos(heroAircraft.getPosX()+heroAircraftWidth/2+bulletWidth/2-4,heroAircraft.getPosY());
}
Bullet::~Bullet()

{
    //dtor
}
