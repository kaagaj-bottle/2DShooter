#ifndef ENTITY_H
#define ENTITY_H

#include "../basicHeader.h"
#include "TextClass.h"

class Entity:public sf::Drawable,sf::Transformable
{
public:

        //setters
    void loadEntity(const std::string& fileName);
    void setCentre(const sf::Vector2f& origin);
    void setCentre(const float centreX,const float centreY);
    void setCentreToOrigin();
    void setVelocity(float vX,float vY);
    void setVelocity(sf::Vector2f v);
    void setPos(float x,float y);
    void setPos(const sf::Vector2f& pos);
    //void rotateClockWise();
    //void rotateAntiClockWise();
    //
    void decreaseBullets();
    void increaseBullets();
    int decreaseHealth();
    void increaseHealth();
    int increaseScore();
    void refillBullet();

    //getter
    const float getPosX();
    const float getPosY();
    const float getVelocityX();
    const float getVelocityY();
    int getBulletsLeft();
    int getHealthLeft();
    int getScore();
    const sf::FloatRect getObjectRect();

    const sf::Vector2f getVelocity();
    void dynamics(sf::Vector2f updatedVelocity);

    //virtual functions

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Entity();


private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
    sf::Vector2f mVelocity;
    int mBulletsLeft;
    int mHealthLeft;
    int mScore;
};

#endif // ENTITY_H
