//object that is the target of the game and grows the snake making it
//more difficult
#ifndef FOOD_H
#define FOOD_H


#include <SDL.h>
#include <string>

#include "displayManager.h"

class Food{
  private:
    SDL_Surface *screen;
    int worldWidth;
    int worldHeight;
    
    SDL_Surface *image;

    Uint16 width;
    Uint16 height;

    float posX;
    float posY;

    bool eaten;

    Food();

  public:
    Food(const std::string);
    ~Food();
    Food(const Food&);
    Food& operator=(const Food&);

    void update(const Position);
    void draw();
    bool checkForCollision(const Position);

    bool isEaten() const { return eaten; }
    void resetPosition(); //eventually add variables so manager can select coord
    float getRandInRange(int min, int max) const;
};

#endif
