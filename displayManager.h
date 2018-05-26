//Display Manager holds the main screen that all other images Blit to
#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <SDL.h>

class DisplayManager {
  private:
    DisplayManager();
    DisplayManager(const DisplayManager&);
    DisplayManager& operator=(const DisplayManager&);

    int windowWidth;
    int windowHeight;
    SDL_Surface *screen;

  public:
    static DisplayManager& getInstance();
    SDL_Surface * getScreen() const {return screen;}
    ~DisplayManager();

};

#endif
