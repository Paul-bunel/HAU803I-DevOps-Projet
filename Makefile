# On appelle les règles re all clean dans tous les cas, même si un fichier du
# même nom existe
.PHONY : re all clean

# Définition des différentes variables
CC = g++# compilateur
CFLAGS = -Wall -Wextra -Wfatal-errors -ansi -pedantic -std=c++2a# flags (= options) à passer au compilateur
SRC_CORE_DIR = src
OBJ_CORE_DIR = obj
SRC_CORE = $(wildcard $(SRC_CORE_DIR)/*.cpp)# fichiers sources
# fichier objets rendus en résultats de la compilation de fichiers sources
# -> identiques à la variable $(SOURCES) mais remplace les .cpp par des .o
OBJ_CORE = $(patsubst src/%.cpp,obj/%.o,$(SRC_CORE))

SRC_MAIN = $(wildcard *.cpp)
OBJ_MAIN = $(patsubst %.cpp,%.o,$(SRC_MAIN))

SRC = $(SRC_MAIN) $(SRC_CORE)
OBJ= $(OBJ_MAIN) $(OBJ_CORE)
EXE=main# nom du fichier executable
ifeq ($(OS),Windows_NT) # change la commande à appeler en fonction de l'OS
	RM=del /S /Q
else
	RM=rm -rf
endif

all : $(OBJ) # vérifie que les fichiers objets soient à jour
# génère l'executable en compilant les fichiers objets (.o) obtenus en
# ammont par la compilation des fichiers sources (.cpp)
	$(CC) -o $(EXE) $(OBJ)

# supprime tout (sauf les fichiers sources évidemment)
clean:
	$(RM) *.o $(EXE)

re : clean all # appel d'un "make re" permet de tout clean puis tout compiler

# compile les fichiers sources (.cpp) pour obtenir les fichiers objets (.o)
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

$(OBJ_CORE_DIR)/%.o : $(SRC_CORE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $<