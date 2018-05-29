//Display Manager holds the main screen that all other images Blit to
#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <SDL.h>

#include <string>

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
    SDL_Surface* loadAndSet( const std::string& );
    int getWidth() { return windowWidth; }
    int getHeight() { return windowHeight; }

};

struct Position{
  float X;
  float Y;
};

#endif
