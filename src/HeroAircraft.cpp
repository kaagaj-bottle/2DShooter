#include "HeroAircraft.h"

HeroAircraft::HeroAircraft(const std::string& textureName)
{
    loadEntity(textureName);
    setVelocity(sf::Vector2f(200.f,200.f));
    setCentre(heroAircraftWidth/2,heroAircraftHeight/2);
    setPos(100.f,screenWidth/2);
}


void HeroAircraft::update(const sf::Time& dt)
{
    sf::Vector2f movement(0.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(getPosY()<=(heroAircraftWidth/2))
        {
            setPos(getPosX(),heroAircraftWidth/2);
        }
        else
        {
            movement.y-=getVelocityY();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(getPosY()>=(screenHeight-heroAircraftHeight/2))
        {
            setPos(getPosX(),screenHeight-heroAircraftHeight/2);
        }
        else
        {
            movement.y+=getVelocityY();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(getPosX()>=(screenWidth-heroAircraftWidth/2))
        {
            setPos(screenWidth-heroAircraftWidth/2,getPosY());
        }
        else
        {
            movement.x+=getVelocityX();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(getPosX()<=heroAircraftWidth/2)
        {
            setPos(heroAircraftWidth/2,getPosY());
        }
        else
        {
            movement.x-=getVelocityX();
        }
    }
    dynamics(movement*dt.asSeconds());
}



HeroAircraft::~HeroAircraft()
{
    //dtor
}
