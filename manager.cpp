
#include <string>

#include "manager.h"

Manager::Manager():
  display( DisplayManager::getInstance() ),
  screen( display.getScreen() ),
  backRed(0),
  backGreen(0),
  backBlue(255)
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
  //draw player
  SDL_Flip(screen);
}

void Manager::update(){
  //update
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
