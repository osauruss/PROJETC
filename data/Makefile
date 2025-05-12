# Makefile pour compiler un programme SFML

# Répertoires pour SFML
SFML_INCLUDE =  SFML-3.0.0/include
SFML_LIB = SFML-3.0.0/lib

# Nom du programme final
TARGET = pokemon

# Fichier source
SRC = pokemon.cpp

# Compilateur
CXX = g++

# Drapeaux pour la compilation et l'édition des liens
CXXFLAGS = -I$(SFML_INCLUDE)
LDFLAGS = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Règle par défaut pour compiler le programme
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
