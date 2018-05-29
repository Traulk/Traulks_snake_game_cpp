
#include <iostream>
#include <limits>

#include "food.h"

Food::~Food(){
  SDL_FreeSurface(image);
}

Food::Food(const std::string fileName) :
  screen(DisplayManager::getInstance().getScreen()),
  worldWidth( DisplayManager::getInstance().getWidth() ),
  worldHeight( DisplayManager::getInstance().getHeight() ),
  image(DisplayManager::getInstance().loadAndSet(fileName)),
  width( 32 ),
  height( 32 ),
  posX(0),
  posY(0),
  eaten(false)
{ }

void Food::update(const Position snakeHead){
  if( checkForCollision(snakeHead) && !eaten){
    eaten = true;
    std::cout << "NOOOOOOOOOOOMMMMMMZZZZ!" << std::endl;
  }
  
}

float Food::getRandInRange(int min, int max) const {
  return min + (rand()/(std::numeric_limits<int>::max()+1.0f))*(max-min);
}

void Food::resetPosition(){
  posX = getRandInRange(0, worldWidth);
  posY = getRandInRange(0, worldHeight);

  eaten = false;
}

bool Food::checkForCollision(const Position sh){
  if( sh.X >= posX &&
      sh.X <= (posX + width) &&
      sh.Y >= posY &&
      sh.Y <= (posY + height) )
  {
    return true;
  }else{ 
    return false; 
  }

}

void Food::draw(){
  if(!eaten){
    Sint16 zero = 0;
    SDL_Rect src = { zero, zero, width, height };

    Uint32 x = static_cast<Uint32>(posX);
    Uint32 y = static_cast<Uint32>(posY);

    Sint16 tx = x;
    Sint16 ty = y;

    SDL_Rect dest = { tx, ty, width, height };
    SDL_BlitSurface( image, &src, screen, &dest );
  }
}
