#warnings
CXXFLAGS=`sdl-config --cflags` -g -W -Wall -Weffc++ -Wextra -pedantic

#Linker Flags
LDFLAGS = `sdl-config --libs` -lSDL_ttf -lSDL_image -lexpat -lSDL_gfx -lSDL_mixer

run: displayManager.o manager.o 
	g++ ${CXXFLAGS} -o run main.cpp manager.o displayManager.o $(LDFLAGS)

displayManager.o: displayManager.h displayManager.cpp
	g++ $(CXXFLAGS) -c displayManager.cpp $(LDFLAGS) 

manager.o: manager.h manager.cpp displayManager.h
	g++ $(CXXFLAGS) -c manager.cpp $(LDFLAGS)



clean:
	rm *.o
	rm run
