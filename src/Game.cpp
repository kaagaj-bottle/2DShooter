#include "Game.h"

Game::Game()
    :mWindow(sf::VideoMode(screenWidth,screenHeight),"myWindow")
    ,mHero{"asset/texture/heroAircraft.png"}
    ,mText{"asset/text/openSans.ttf"}
    ,mLevel{0}
    ,mAdditionalObject{}

{


    mBackgroundTexture.loadFromFile("asset/texture/background.jpg");
    mBackgroundSprite.setTexture(mBackgroundTexture);
    mText.setBulletsLeft(totalBullet);
    mText.setHealthLeft(5);
    mText.setScore(0);
    mHeroBulletVector.reserve(50);
    mObstacleVector.reserve(9);
    fillObstacleVector();

    fillObstacleVector();
    mText.setLevel(0);
    mBulletSoundBuffer.loadFromFile("asset/sound/bulletSound.ogg");
    mBulletSound.setBuffer(mBulletSoundBuffer);


}

void Game::run()
{


    //bullet clock has been created so as to create a delay between subsequent firings
    sf::Clock clock;
    sf::Clock bulletClock;
    sf::Time timeSinceLastUpdate=sf::Time::Zero;
    sf::Time bulletDelay=sf::Time::Zero;
    while(mWindow.isOpen())
    {
        processEvents();

        timeSinceLastUpdate+=clock.restart();
        while(timeSinceLastUpdate>TimePerFrame)
        {
            bulletDelay=bulletClock.getElapsedTime();
            if(bulletDelay.asSeconds()>=0.1)
            {
                updateBullet();
                bulletDelay=sf::Time::Zero;
                bulletClock.restart();
            }

            if(mObstacleVector.size()==0)
            {
                ++mLevel;
                mText.setLevel(mLevel);
                fillObstacleVector();
            }
            updateObstacles();
            timeSinceLastUpdate-=TimePerFrame;
            mHero.update(TimePerFrame);
        }
        render();
        if(mLevel>9)
        {
            std::cout<<"okay we are done here \n";
            break;
        }
    }

}


void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
        break;
        }
    }
}

void Game::updateBullet()
{
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
    {
        if(mHero.getBulletsLeft()>0)
        {
            mBulletSound.play();
            mHero.decreaseBullets();
            Bullet* newBullet=new Bullet("asset/texture/bullet.png");
            newBullet->update(mHero);
            mHeroBulletVector.push_back(std::move(*newBullet));
            mText.setBulletsLeft(mHero.getBulletsLeft());
        }
        else
        {
            mText.setHelpText1();
        }
    }

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::R))&&mHero.getBulletsLeft()<=0)
    {

        mHeroBulletVector.clear();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {

            mHero.refillBullet();
        }
        mText.setBulletsLeft(mHero.getBulletsLeft());
        mText.disableHelpText1();
    }
}
void Game::render()
{
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mBackgroundSprite);
    if(!((mLevel<totalLevel)&&(mHero.getHealthLeft()>0)))
    {
        std::cout<<"Bullets     :"<<mHero.getBulletsLeft()<<'\n';
        std::cout<<"Score       :"<<mHero.getScore()<<'\n';
        std::cout<<"Health      :"<<mHero.getHealthLeft()<<'\n';
        std::cout<<"Level       :"<<mLevel<<'\n';
        mText.setGameOverText();
        mWindow.draw(mText);

    }
    else
    {
         for(std::size_t index{0};index<mHeroBulletVector.size();++index)
        {
            mWindow.draw(mHeroBulletVector[index]);
            mHeroBulletVector[index].dynamics(mHeroBulletVector[index].getVelocity());
        }

        bulletObstacleCollision();
        for(std::size_t index{0};index<mObstacleVector.size();++index)
        {
            mWindow.draw(mObstacleVector[index]);
        }

        mWindow.draw(mText);
        mWindow.draw(mHero);

    }
    mWindow.draw(mAdditionalObject);

    mWindow.display();

}

void Game::fillObstacleVector()
{
    mObstacleVector.clear();
    mHeroBulletVector.clear();
    for(std::size_t index{0};index<totalObstacles;++index)
    {
        std::string filename="asset/texture/obstacle"+std::to_string(mLevel)+".png";
        Obstacles* ob=new Obstacles(index,filename);
        mObstacleVector.push_back(*ob);
    }
}

void Game::updateObstacles()
{
    for(std::size_t index{0};index<totalObstacles;++index)
    {
        mObstacleVector[index].update(mLevel);
    }
}

void Game::bulletObstacleCollision()
{
    for(std::size_t oIndex{0};oIndex<mHeroBulletVector.size();++oIndex)
    {

        for(std::size_t iIndex{0};iIndex<mObstacleVector.size();++iIndex)
        {
            if(mObstacleVector[iIndex].checkBulletCollision(&mHeroBulletVector[oIndex]))
            {

                mHeroBulletVector.erase(mHeroBulletVector.begin()+oIndex);
                mObstacleVector.erase(mObstacleVector.begin()+iIndex);
                mText.setScore(mHero.increaseScore());

            }

            if(mObstacleVector[iIndex].getPosX()<=0)
            {
                mObstacleVector.erase(mObstacleVector.begin()+iIndex);
                mText.setHealthLeft(mHero.decreaseHealth());
            }

            if(mHeroBulletVector[oIndex].getPosX()>=screenWidth-bulletWidth/2)
            {
                mHeroBulletVector[oIndex].setPos(-100.f,-100.f);
            }

//            if(mObstacleVector[iIndex].checkHeroCollision(&mHero))
//            {
//                //mObstacleVector[iIndex]
//                mText.setHealthLeft(mHero.decreaseHealth());
//            }
        }

    }

}

Game::~Game()
{
   // delete mBullet;

}


