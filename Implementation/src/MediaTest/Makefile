CC=g++
CXXFLAGS=-pedantic -Wall -std=c++11
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SOURCES=$(wildcard ../Video/*.cpp) $(wildcard ../Audio/*.cpp) $(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))
EXECUTABLE=mediatest

all: $(EXECUTABLE)
	@echo "Created: $(EXECUTABLE)"
$(EXECUTABLE): $(OBJECTS)
	@echo "Linking objects..."
	@$(CC) $(LDFLAGS) -o $@ $^
build/%.o: src/%.cpp
	@echo "Building: $^..."
	@mkdir -p build/{audio,video}
	@$(CC) $(CXXFLAGS) -c $^ -o $@
clean:
	@rm -f $(EXECUTABLE) $(OBJECTS)
