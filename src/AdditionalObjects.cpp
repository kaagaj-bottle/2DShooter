#include "AdditionalObjects.h"

AdditionalObjects::AdditionalObjects()
{
    if(!mBulletTexture.loadFromFile("asset/texture/bulletAdditional.png"))
    {
        std::cerr<<"failed to load the bullet.png in additional objects: \n";
    }
    if(!mHealthTexture.loadFromFile("asset/texture/health.png"))
    {
        std::cerr<<"failed to load health.png in additional objects: \n";
    }
    if(!mScoreTexture.loadFromFile("asset/texture/score.png"))
    {
        std::cerr<<"failed to load score.png in additional objects\n";
    }

    mBulletSprite.setTexture(mBulletTexture);
    mBulletSprite.setPosition(0.f,8.f);
    mHealthSprite.setTexture(mHealthTexture);
    mHealthSprite.setPosition(0.f,24.f);
    mScoreSprite.setTexture(mScoreTexture);
    mScoreSprite.setPosition(0.f,48.f);

}

void AdditionalObjects::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mBulletSprite);
    target.draw(mHealthSprite);
    target.draw(mScoreSprite);
}

AdditionalObjects::~AdditionalObjects()
{
    //dtor
}
