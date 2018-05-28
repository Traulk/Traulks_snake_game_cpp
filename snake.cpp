
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
  posX(0.0),
  posY(0.0),
  speed(width/2),
  tailSize(3),
  up(false),
  down(false),
  left(false),
  right(false)
{
 //stuff 
}

void Snake::update(Uint32 ticks){
  float incr = speed * static_cast<float>(ticks) * 0.01;
  updatePosition(incr);
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
  if(up) posY -= incr;
  if(down) posY += incr;
  if(right) posX += incr;
  if(left) posX -= incr; 

  updateTail();
}

void Snake::updateTail(){
  
}

void Snake::draw(){
  Sint16 zero = 0;
  SDL_Rect src = { zero, zero, width, height };

  Uint32 x = static_cast<Uint32>(posX);
  Uint32 y = static_cast<Uint32>(posY);

  Sint16 tx = x;
  Sint16 ty = y;

  SDL_Rect dest = { tx, ty, width, height };
  SDL_BlitSurface( image, &src, screen, &dest );
}
