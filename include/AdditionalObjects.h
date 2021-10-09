#ifndef ADDITIONALOBJECTS_H
#define ADDITIONALOBJECTS_H
#include "../basicHeader.h"

class AdditionalObjects:public sf::Drawable,sf::Transformable
{
public:
    AdditionalObjects();
    virtual ~AdditionalObjects();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

private:
    sf::Sprite mBulletSprite;
    sf::Texture mBulletTexture;

    sf::Sprite mHealthSprite;
    sf::Texture mHealthTexture;

    sf::Sprite mScoreSprite;
    sf::Texture mScoreTexture;

};

#endif // ADDITIONALOBJECTS_H
