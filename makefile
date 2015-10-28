# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
.SUFFIXES:

# variables
CXXFLAGS= -I"include/"

all : main.o core.o
	g++ $(CXXFLAGS) -o build/release/NodeSound main.o core.o
	
main.o : core.o
	g++ $(CXXFLAGS) -o main.o src/main.cpp
	
core.o : 
	g++ $(CXXFLAGS) -o core.o src/core/core.cpp

# suppression des fichiers temporaires
clean:
	rm -rf *.o

# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf NodeSound
