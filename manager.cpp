
#include <string>
#include <iostream>

#include "manager.h"

Manager::Manager():
  display( DisplayManager::getInstance() ),
  screen( display.getScreen() ),
  backRed(255),
  backGreen(255),
  backBlue(255),
  player("images/blue_square.png"),
  target("images/blue_square.png"),
  ticks(0),
  sumOfTicks(0),
  cap(5)
{
  if( SDL_Init(SDL_INIT_VIDEO) != 0){
    throw( std::string("Unable to init SDL: ") + SDL_GetError());
  }
  atexit(SDL_Quit);
}

Manager::~Manager(){

}

void Manager::drawBackground(){
  SDL_FillRect( screen, NULL, 
    SDL_MapRGB(screen->format, backRed, backGreen, backBlue) );
  SDL_Rect dest = {0, 0, 0, 0};
  SDL_BlitSurface( screen, NULL, screen, &dest );
}

void Manager::draw(){
  drawBackground();
  player.draw();
  target.draw();
  SDL_Flip(screen);
}

void Manager::update(){
  /*if((SDL_GetTicks() - sumOfTicks) < 1000 / static_cast<float>(cap)){
    SDL_Delay( ( 1000 / static_cast<float>(cap) ) - (SDL_GetTicks() - sumOfTicks) );
  }*/

  ticks = SDL_GetTicks() - sumOfTicks;
  sumOfTicks += ticks;
  //update
  player.update(ticks);
  target.update(player.getPosition());

  if(target.isEaten()){
    //reset in new position and add point
    std::cout << "woot woot the manager found out" << std::endl;
  }
}

void Manager::play(){
  SDL_Event event;

  bool done = false;
  while( not done){
    while ( SDL_PollEvent(&event) ) {
      Uint8 *keystate = SDL_GetKeyState(NULL);
      if (event.type ==  SDL_QUIT) { done = true; break; }
      if (event.type == SDL_KEYDOWN) {
        if (keystate[SDLK_ESCAPE] || keystate[SDLK_q]) {
          done = true;
          break;
        }
      }
    }

    draw();
    update();
  }
}
