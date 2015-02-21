CC = g++
CPPFLAGS = -Wall -g -I$(INCLUDE) -std=c++11
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

all:ejercicios pruebas

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

ejercicios:$(BIN)/testdiccionario $(BIN)/letras $(BIN)/Cantidad_letras

$(BIN)/letras:$(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_letras.o $(OBJ)/Bolsa_letras.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/testdiccionario:$(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_letras.o $(OBJ)/Bolsa_letras.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/Cantidad_letras:$(OBJ)/Cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_letras.o $(OBJ)/Bolsa_letras.o
	$(CC) $(CPPFLAGS) -o $@ $^

pruebas: $(BIN)/prueba_arbol $(BIN)/prueba_conjunto_letras $(BIN)/prueba_bolsa_letras

$(BIN)/prueba_arbol:$(OBJ)/prueba_arbol.o
	$(CC) $(CPPFLAGS) -o $@ $<

$(BIN)/prueba_conjunto_letras:$(OBJ)/prueba_conjunto_letras.o $(OBJ)/Conjunto_letras.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/prueba_bolsa_letras:$(OBJ)/prueba_bolsa_letras.o $(OBJ)/Conjunto_letras.o $(OBJ)/Bolsa_letras.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $< 2> salida


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
