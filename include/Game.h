#ifndef GAME_H
#define GAME_H
#include "../basicHeader.h"
#include "HeroAircraft.h"
#include "Bullet.h"
#include "EnemyAircraft.h"
#include "TextClass.h"
#include "Obstacles.h"
#include "AdditionalObjects.h"
#include "Audio.hpp"
const sf::Time TimePerFrame=sf::seconds(1.f/60.f);


class Game
{
public:
    Game();
    void run();
    ~Game();

private:
    void processEvents();
    void updateBullet();
    void render();
    void fillObstacleVector();
    void updateObstacles();
    void bulletObstacleCollision();
private:
    sf::RenderWindow mWindow;
    sf::Texture mBackgroundTexture;
    sf::Sprite mBackgroundSprite;

    //contents of player
    TextClass mText;
    HeroAircraft mHero;
    sf::SoundBuffer mBulletSoundBuffer;
    sf::Sound mBulletSound;

    std::vector<Bullet> mHeroBulletVector;
    std::vector<Obstacles> mObstacleVector;

    AdditionalObjects mAdditionalObject;
    bool mIsFiring;
    bool hit;
    //for random number


    unsigned int mLevel;

};

#endif // GAME_H

