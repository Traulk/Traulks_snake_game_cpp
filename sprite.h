//sprite class

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

#include "displayManager.h"

class Sprite{
  private:
    SDL_Surface *screen;

    SDL_Surface *image;
    Uint16 width;
    Uint16 height;

    float posX;
    float posY;

  public:
    Sprite();
    ~Sprite();
    Sprite(const Sprite&);
    Sprite& operator=(const Snake&);

};

#endif
