COMPILER = g++
SOURCES := $(wildcard src/*.cpp)
INCLUDES := $(wildcard src/*.hpp)
RESOURCES := $(wildcard res/*.o)
SFML_PATH := $(wildcard C:\\Users\\r0ck\\Desktop\\Wirgiliusz\\Programowanie\\SFML-2.4.0)
EXE_NAME = Tic-Tac-Toe

all: $(SOURCES)
	$(COMPILER) -Wall -pedantic -mwindows $(RESOURCES) $(SOURCES) -I$(SFML_PATH)\\include -L$(SFML_PATH)\\lib -lsfml-graphics -lsfml-window -lsfml-system -o $(EXE_NAME)
