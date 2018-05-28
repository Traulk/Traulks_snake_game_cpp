
#include <iostream>
#include <SDL_image.h>

#include "displayManager.h"

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

//funtion for loading in all image files to SDL_Surfaces
SDL_Surface * DisplayManager::loadAndSet( const std::string& fileName){
  SDL_Surface *temp = IMG_Load( fileName.c_str() );
  //add code for handling transparancy color here
  SDL_Surface *image = SDL_DisplayFormatAlpha(temp);
  if( image == NULL ){
    image = temp;
  }else{
    SDL_FreeSurface(temp);
  }
  return image;
}
