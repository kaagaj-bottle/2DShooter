#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "Entity.h"
#include "../basicHeader.h"
#include "Bullet.h"
#include "HeroAircraft.h"
class Obstacles:public Entity
{
    public:
        Obstacles(int index,const std::string& filename);
        void update(int level);
        bool checkBulletCollision(Bullet* bullet);
        bool checkHeroCollision(HeroAircraft* hero);
        virtual ~Obstacles();

    private:




};

#endif // OBSTACLES_H
