# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
.SUFFIXES:

# variables
CXXFLAGS= -Iinclude  -I/home/datross/Programmation/Librairies/portaudio/include/ -lrt -lpthread -lasound -Wall

all : main.o core.o
	g++ libportaudio.a build/main.o build/core.o $(CXXFLAGS) -o bin/release/NodeSound
	
main.o : core.o
	g++ -c src/main.cpp $(CXXFLAGS) -o build/main.o
	
core.o : unwrappedConnectionTypes.o wrappedConnectionTypes.o
	g++ -c src/core/core.cpp $(CXXFLAGS) -o build/core.o
	
wrappedConnectionTypes.o : unwrappedConnectionTypes.o
	g++ -c src/core/wrappedConnectionTypes.cpp $(CXXFLAGS) -o build/wrappedConnectionTypes.o
	
unwrappedConnectionTypes.o :
	g++ -c src/core/unwrappedConnectionTypes.cpp $(CXXFLAGS) -o build/unwrappedConnectionTypes.o

# suppression des fichiers temporaires
clean:
	rm -rf build/*.o
