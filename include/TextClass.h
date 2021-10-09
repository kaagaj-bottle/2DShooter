#ifndef TEXTCLASS_H
#define TEXTCLASS_H
#include "../basicHeader.h"
#include <string>

class TextClass:public sf::Drawable,sf::Transformable
{
    public:
        TextClass(const std::string& fileName);
        void setBulletsLeft(int bulletsLeft);
        void setHealthLeft(int healthLeft);
        void setScore(int score);
        void setLevel(int level);
        void setHelpText1();
        void setGameOverText();
        void disableHelpText1();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        virtual ~TextClass();

    protected:

    private:
        sf::Font mFont;
        sf::Text mBulletsLeft;
        sf::Text mHealthLeft;
        sf::Text mScore;
        sf::Text mLevel;
        sf::Text mHelpText1;
        std::string mString;
        sf::Text mGameOver;
};

#endif // TEXTCLASS_H
