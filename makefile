# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
.SUFFIXES:

# variables
CXXFLAGS= -I"include/"

all : main.o core.o
	g++ main.o core.o $(CXXFLAGS) -o build/release/NodeSound
	
main.o : core.o
	g++ src/main.cpp $(CXXFLAGS) -o main.o
	
core.o : 
	g++ src/core/core.cpp $(CXXFLAGS) -o core.o

# suppression des fichiers temporaires
clean:
	rm -rf *.o

# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf NodeSound
