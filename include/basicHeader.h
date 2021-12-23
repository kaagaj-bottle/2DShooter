#ifndef BASICHEADER_H_INCLUDED
#define BASICHEADER_H_INCLUDED

#include <iostream>
#include "Graphics.hpp"
#include "Window.hpp"
#include "System.hpp"

//screen dimensions
constexpr int screenWidth=960;
constexpr int screenHeight=600;

//hero aircraft dimensions
constexpr int heroAircraftWidth=112;
constexpr int heroAircraftHeight=108;

//bullet dimensions
constexpr int bulletWidth=40;
constexpr int bulletHeight=14;
constexpr int totalBullet=100;

//enemy aircraft dimensions
constexpr int enemyAircraftWidth=96;
constexpr int enemyAircraftHeight=90;

//here totalObstacles refers to the total obstacles in single level
constexpr int totalObstacles=6;
constexpr int totalLevel=20;

#endif // BASICHEADER_H_INCLUDED
