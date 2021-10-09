#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"
#include "HeroAircraft.h"
#include "../basicHeader.h"
#include <array>


class Bullet:public Entity
{
public:
    Bullet(const std::string& textureName);
    void update(HeroAircraft& HeroAircraft);

    virtual ~Bullet();
protected:

private:
    //static variable
    static int bulletCounter;
};

#endif // BULLET_H
