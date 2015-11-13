INC=-I../src -I../src/Audio -I../src/Video -I../src/Engine
CC=g++
CXXFLAGS=-pedantic -Wall -std=c++11 $(INC)
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SOURCES=$(wildcard ../src/Audio/*.cpp) $(wildcard ../src/Video/*.cpp)
OBJECTS=$(patsubst ../src/%.cpp, build/%.o, $(SOURCES))
EXECUTABLE=mediatest

all: $(EXECUTABLE)
	@echo "Created: $(EXECUTABLE)"
$(EXECUTABLE): $(OBJECTS) Main.o
	@echo "Linking objects..."
	@$(CC) $(LDFLAGS) -o $@ $^
build/%.o: ../src/%.cpp
	@echo "Building: $^..."
	@mkdir -p build/{Audio,Video}
	@$(CC) $(CXXFLAGS) -c $^ -o $@
Main.o: Main.cpp
	@$(CC) $(CXXFLAGS) -c $^ -o $@
clean:
	@rm -f $(EXECUTABLE) $(OBJECTS) Main.o
