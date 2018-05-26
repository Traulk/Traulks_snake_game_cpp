//main management class. holds other managers and controls the gmae

#ifndef MANAGER_H
#define MANGER_H

#include <SDL.h>
#include "displayManager.h"

class Manager {
  private:
    const DisplayManager& display;

    SDL_Surface *screen;
    int backRed;
    int backGreen;
    int backBlue;

    void drawBackground();
    void draw();
    void update();
  public:
    Manager();
    ~Manager();
    void play();
};

#endif
