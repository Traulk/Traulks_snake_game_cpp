//main management class. holds other managers and controls the gmae

#ifndef MANAGER_H
#define MANGER_H

#include <SDL.h>
#include "displayManager.h"
#include "snake.h"
#include "food.h"


class Manager {
  private:
    const DisplayManager& display;

    SDL_Surface *screen;
    int backRed;
    int backGreen;
    int backBlue;

    Snake player;

    Food target;

    unsigned int ticks;
    unsigned int sumOfTicks;
    int cap;

    void drawBackground();
    void draw();
    void update();
  public:
    Manager();
    ~Manager();
    Manager(const Manager&);
    Manager& operator=(const Manager&);
    void play();
};

#endif
