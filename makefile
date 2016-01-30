# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
.SUFFIXES:

# variables
CXXFLAGS= -Iinclude -Wall

all : main.o core.o
	g++ build/main.o build/core.o $(CXXFLAGS) -o bin/release/NodeSound
	
main.o : core.o
	g++ -c src/main.cpp $(CXXFLAGS) -o build/main.o
	
core.o : 
	g++ -c src/core/core.cpp $(CXXFLAGS) -o build/core.o

# suppression des fichiers temporaires
clean:
	rm -rf build/*.o
