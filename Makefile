# On appelle les règles re all clean dans tous les cas, même si un fichier du
# même nom existe
.PHONY : re all clean

# Définition des différentes variables
CC = g++ # compilateur

# flags (= options) à passer au compilateur
CFLAGS = -Wall -Wextra -Wfatal-errors -MMD -ansi -pedantic -std=c++2a

SRC_CORE_DIR = src # dossier contenant les fichiers sources
OBJ_CORE_DIR = obj # dossier contenant les fichiers objets

# fichiers sources contenus dans le dossier src
SRC_CORE = $(wildcard $(SRC_CORE_DIR)/*.cpp)
# fichiers objet contenus dans le dossier src (remplace le path des fichiers src)
OBJ_CORE = $(patsubst src/%.cpp,obj/%.o,$(SRC_CORE))

SRC_MAIN = $(wildcard *.cpp) # sources à la racine de l'arborescence
OBJ_MAIN = $(patsubst %.cpp,%.o,$(SRC_MAIN)) # objets à la racine de l'arborescence

SRC = $(SRC_MAIN) $(SRC_CORE) # concaténation de toutes les sources
OBJ= $(OBJ_MAIN) $(OBJ_CORE) # concaténation de tous les objets

LIBS_FLAGS = -Iinclude -I. # indique où chercher les fichiers à inclure

EXE=main_exe # nom du fichier executable
ifeq ($(OS),Windows_NT) # change la commande à appeler en fonction de l'OS
	RM=del /S /Q
else
	RM=rm -rf
endif

all : $(OBJ) # vérifie que les fichiers objets soient à jour
# génère l'executable en compilant les fichiers objets (.o) obtenus en
# ammont par la compilation des fichiers sources (.cpp)
	$(CC) $(CFLAGS) $^ -o $(EXE) $(LIBS_FLAGS)

# supprime tous les fichiers objets + l'exécutable
clean:
	$(RM) *.o *.d $(EXE)

re : clean all # l'appel d'un "make re" permet de tout clean puis tout compiler

# compile les fichiers sources (.cpp) pour obtenir les fichiers objets (.o)
%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS_FLAGS)

$(OBJ_CORE_DIR)/%.o : $(SRC_CORE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS_FLAGS)

-include $(OBJ:.o=.d)
