# On appelle les règles re all clean dans tous les cas, même si un fichier du
# même nom existe
.PHONY : re all clean

# Définition des différentes variables
CC=g++# compilateur
CFLAGS=-Wall -Wextra -ansi -pedantic -std=c++2a# flags (= options) à passer au compilateur
SRC=main.cpp FileHandler.cpp FastaHandler.cpp SequenceHandler.cpp# fichiers sources
# fichier objets rendus en résultats de la compilation de fichiers sources
# -> identiques à la variable $(SOURCES) mais remplace les .cpp par des .o
OBJ=$(SRC:%.cpp=%.o)
EXE=main# nom du fichier executable
ifeq ($(OS),Windows_NT) # change la commande à appeler en fonction de l'OS
	RM=del
else
	RM=rm
endif

all : $(OBJ) # vérifie que les fichiers objets soient à jour
# génère l'executable en compilant les fichiers objets (.o) obtenus en
# ammont par la compilation des fichiers sources (.cpp)
	$(CC) -o $(EXE) $(OBJ)

# supprime tout (sauf les fichiers sources évidemment)
clean:
	$(RM) -f *~ *.o $(EXE)

re : clean all # appel d'un "make re" permet de tout clean puis tout compiler

# compile les fichiers sources (.cpp) pour obtenir les fichiers objets (.o)
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<