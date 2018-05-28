#warnings
CXXFLAGS=`sdl-config --cflags` -g -W -Wall -Weffc++ -Wextra -pedantic -O0

#Linker Flags
LDFLAGS = `sdl-config --libs` -lSDL_ttf -lSDL_image -lexpat -lSDL_gfx -lSDL_mixer

run: displayManager.o manager.o snake.o
	g++ ${CXXFLAGS} -o run main.cpp manager.o snake.o displayManager.o $(LDFLAGS)

displayManager.o: displayManager.h displayManager.cpp
	g++ $(CXXFLAGS) -c displayManager.cpp $(LDFLAGS) 

manager.o: manager.h manager.cpp displayManager.h
	g++ $(CXXFLAGS) -c manager.cpp $(LDFLAGS)

snake.o: snake.h displayManager.h
	g++ $(CXXFLAGS) -c snake.cpp $(LDFLAGS) 

clean:
	rm *.o
	rm run
