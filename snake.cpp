#include <iostream>

#include "snake.h"

Snake::~Snake(){

}

Snake::Snake(const std::string& fileName) : 
  screen(DisplayManager::getInstance().getScreen()),
  worldWidth( DisplayManager::getInstance().getWidth() ),
  worldHeight( DisplayManager::getInstance().getHeight() ),
  image(DisplayManager::getInstance().loadAndSet(fileName)),
  width( 32 ),
  height( 32 ),
  posX(32.0),
  posY(129.0),
  speed(width),
  tailSize(3),
  tail(),
  up(false),
  down(false),
  left(false),
  right(false),
  waitToTicks(100),
  sumOfTicks(0)
{
  //create starting tail
  for(int i = 1; i <= tailSize; i++){
    //float newX = posX - (width * i);
    float newY = posY - (height * i);
    Position temposition = {posX, newY};
    tail.push_back(temposition);
 } 
}

void Snake::update(Uint32 ticks){
  //float incr = speed * static_cast<float>(ticks);
  sumOfTicks += ticks;
  if(sumOfTicks >= waitToTicks){
    float incr = width;
    updatePosition(incr);
    sumOfTicks = 0;
  }
  //check for player input
  Uint8 *keystate = SDL_GetKeyState(NULL);

  if( keystate[SDLK_w] ){
    up = true; down = false; left = false; right = false; 
   /* if(posY >= 0){
      posY = 0;
    }else{ posY -= height; }*/
  }
  if( keystate[SDLK_a] ){
    up = false; down = false; left = true; right = false; 
  //  posX -= width;
  }
  if( keystate[SDLK_s] ){
    up = false; down = true; left = false; right = false; 
    //posY += height;
  }
  if( keystate[SDLK_d] ){
    up = false; down = false; left = false; right = true; 
   // posX += width;
  }


  
  //check for time passed and update movement
  

}

void Snake::updatePosition(float incr){
  float oldX = posX;
  float oldY = posY;

  if(up) posY -= incr;
  if(down) posY += incr;
  if(right) posX += incr;
  if(left) posX -= incr; 
   
  if(up || down || right || left){
    updateTail(oldX, oldY);
  }
}

Position Snake::getPosition(){
  Position temp = {posX, posY};
  return temp;
}

void Snake::updateTail( const float oldX, const float oldY){
 //update positions of tail
 /*
  * for size of tail
  * if first tail piece move to heads position
  * else move to old position of previous*/

  for(int i = tail.size()-1; i >= 0; i--){
    if(i == 0){
      tail[i].X = oldX;
      tail[i].Y = oldY;
    }else{
      tail[i].X = tail[i-1].X;
      tail[i].Y = tail[i-1].Y;
    }
  }
  //code to eventually replace to allow for smoother following and fps
  /*for(int i = 0; i < tailSize; i++){
    if(i == 0){
      if( tail[i].X + width < posX){
        tail[i].X = posX - width;
      }else if( tail[i].X - width < posX){
        tail[i].X = posX + width;
  }*/
}

void Snake::draw(){
  //drawing head
  Sint16 zero = 0;
  SDL_Rect src = { zero, zero, width, height };

  Uint32 x = static_cast<Uint32>(posX);
  Uint32 y = static_cast<Uint32>(posY);

  Sint16 tx = x;
  Sint16 ty = y;

  SDL_Rect dest = { tx, ty, width, height };
  SDL_BlitSurface( image, &src, screen, &dest );

  //drawing tail
  for(int i = 0; i < tailSize; i++){
    x = static_cast<Uint32>(tail[i].X);
    y = static_cast<Uint32>(tail[i].Y);

    tx = x;
    ty = y;
    //std::cout << "printing tail" << i << std::endl;
    SDL_Rect dest2 = { tx, ty, width, height };
    SDL_BlitSurface( image, &src, screen, &dest2 );
  }
}
