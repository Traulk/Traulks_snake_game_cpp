//player controlled class

#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <string>
#include <vector>

#include "displayManager.h"

struct Position;

class Snake {
  private:
    SDL_Surface *screen;
    int worldWidth;
    int worldHeight;
    
    SDL_Surface *image;

    Uint16 width;
    Uint16 height;

    float posX;
    float posY;
    float speed;

    int tailSize;
    std::vector<Position> tail;

    bool up;
    bool down;
    bool left;
    bool right;

    unsigned int waitToTicks;
    unsigned int sumOfTicks;
    //drawn object
    Snake();
    void updatePosition(float);
    void updateTail(const float, const float);

  public:
    Snake(const std::string&);
    ~Snake();
    Snake(const Snake&);
    Snake& operator=(const Snake&);

    void update(Uint32);
    void draw();

    Position getPosition();

};


#endif
