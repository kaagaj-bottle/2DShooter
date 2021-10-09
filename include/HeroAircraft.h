#ifndef HEROAIRCRAFT_H
#define HEROAIRCRAFT_H
#include "Entity.h"


class HeroAircraft:public Entity
{
public:
    HeroAircraft(const std::string& textureName);

    //updating events for the hero aircraft
    void update(const sf::Time& dt);

    virtual ~HeroAircraft();

private:
    float mPlayerSpeed;



};

#endif // HEROAIRCRAFT_H
