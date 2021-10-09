#include "TextClass.h"

TextClass::TextClass(const std::string& fileName)
{
    if(!mFont.loadFromFile(fileName))
    {
        std::cerr<<"could not load "<<fileName<<'\n';

    }




    //settting the font
    mBulletsLeft.setFont(mFont);
    mHealthLeft.setFont(mFont);
    mScore.setFont(mFont);
    mLevel.setFont(mFont);
    mHelpText1.setFont(mFont);
    mGameOver.setFont(mFont);
    //setting the position
    mBulletsLeft.setPosition(24.f,0.f);
    mHealthLeft.setPosition(24.f,24.f);
    mScore.setPosition(24.f,48.f);
    mLevel.setPosition(0.f,72.f);
    mHelpText1.setPosition(screenWidth/2,screenWidth/2);
    mGameOver.setPosition(screenWidth/2,screenHeight/2);
    //setting character size

    mBulletsLeft.setCharacterSize(24);
    mHealthLeft.setCharacterSize(24);
    mScore.setCharacterSize(24);
    mLevel.setCharacterSize(24);
    mHelpText1.setCharacterSize(24);
    mGameOver.setCharacterSize(48);



    //setting text origin

}

void TextClass::setBulletsLeft(int bulletsLeft)
{
    mString="   :"+std::to_string(bulletsLeft);
    mBulletsLeft.setString(mString);

}

void TextClass::setHealthLeft(int healthLeft)
{
    mString="   :"+std::to_string(healthLeft);
    mHealthLeft.setString(mString);
}

void TextClass::setScore(int score)
{
    mString="   :"+std::to_string(score);
    mScore.setString(mString);
}

void TextClass::setLevel(int level)
{
    mString="lvl   :"+std::to_string(level);
    mLevel.setString(mString);
}

void TextClass::setHelpText1()
{
    mHelpText1.setString("No Bullets left press R once more to refill");
}

void TextClass::setGameOverText()
{
    mGameOver.setString("GAME OVER");
}
void TextClass::disableHelpText1()
{

    mHelpText1.setString("");
}


void TextClass::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mHealthLeft);
    target.draw(mBulletsLeft);
    target.draw(mScore);
    target.draw(mLevel);
    target.draw(mHelpText1);
    target.draw(mGameOver);
}
TextClass::~TextClass()
{
    //dtor
}
