#include "Entity.h"

Entity::Entity()
{
    mBulletsLeft=totalBullet;
    mHealthLeft=5;
    mScore=0;

}
void Entity::loadEntity(const std::string& fileName)
{

    if(!mTexture.loadFromFile(fileName))
    {
        std::cerr<<"could not load the texture: "<<fileName<<'\n';
    }
    mSprite.setTexture(mTexture);

}

void Entity::setCentre(const sf::Vector2f& centre)
{
    mSprite.setOrigin(centre);
}

void Entity::setCentre(const float centreX,const float centreY)
{
    mSprite.setOrigin(centreX,centreY);
}

void Entity::setCentreToOrigin()
{
    setCentre(mTexture.getSize().x/2,mTexture.getSize().y/2);
}
void Entity::setVelocity(float vX,float vY)
{
    mVelocity.x=vX;
    mVelocity.y=vY;
}

void Entity::setVelocity(sf::Vector2f v)
{
    mVelocity=v;
}

void Entity::setPos(float x,float y)
{
    mSprite.setPosition(x,y);
}

void Entity::setPos(const sf::Vector2f& pos)
{
    mSprite.setPosition(pos);
}

void Entity::decreaseBullets()
{
    --mBulletsLeft;
}

void Entity::increaseBullets()
{
    mBulletsLeft+=5;
}

int Entity::decreaseHealth()
{
    return  --mHealthLeft;
}
void Entity::increaseHealth()
{
    mHealthLeft+=2;
}
int Entity::increaseScore()
{
    return ++mScore;
}
void Entity::refillBullet()
{
    mBulletsLeft=totalBullet;
}

const sf::Vector2f Entity::getVelocity()
{
    return mVelocity;
}

const float Entity::getPosX()
{
    return mSprite.getPosition().x;
}

const float Entity::getPosY()
{
    return mSprite.getPosition().y;
}

const float Entity::getVelocityX()
{
    return mVelocity.x;
}

const float Entity::getVelocityY()
{
    return mVelocity.y;
}

int Entity::getBulletsLeft()
{
    return mBulletsLeft;
}

int Entity::getHealthLeft()
{
    return mHealthLeft;
}

int Entity::getScore()
{
    return mScore;
}

const sf::FloatRect Entity::getObjectRect()
{
    return mSprite.getGlobalBounds();
}


void Entity::dynamics(sf::Vector2f updatedVelocity)
{
    mSprite.move(updatedVelocity);
}



void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite);
}
