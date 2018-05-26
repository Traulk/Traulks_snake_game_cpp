#include "displayManager.h"
#include <string>
#include <iostream>

DisplayManager::DisplayManager() :
  windowWidth(854),
  windowHeight(400),
  screen(SDL_SetVideoMode( windowWidth, windowHeight, 0, SDL_DOUBLEBUF))
{
  //construction
}

DisplayManager& DisplayManager::getInstance(){
  static DisplayManager dispManager;
  return dispManager;
}

DisplayManager::~DisplayManager(){
//decontructor
}
