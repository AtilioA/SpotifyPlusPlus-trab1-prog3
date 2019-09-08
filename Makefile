OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O3
EXE 	 := indexador
PROJETO  := tp1prog3-AtilioDadalto-TiagoSantos

# Cria objetos de todos os arquivos de código-fonte para então linká-los no programa final
main: $(OBJ)/lista_encadeada.o $(OBJ)/$(PROJETO).o
	g++ $(OBJ)/*.o -o $(EXE) $(CFLAGS)


$(OBJ)/lista_encadeada.o: $(SRC)/lista_encadeada.c $(INC)/lista_encadeada.h
	g++ -c $(CFLAGS) "$(SRC)/lista_encadeada.c" -o "$(OBJ)/lista_encadeada.o"

$(OBJ)/$(PROJETO).o: $(PROJETO).c
	g++ -c $(CFLAGS) $(PROJETO).c -o "$(OBJ)/$(PROJETO).o"

# Limpa objetos e o executável do programa (para Linux)
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)

# Limpa objetos e o executável do programa (para Windows)
cleanW:
	del /F/Q/S "$(OBJ)\*.o"
	del /F/Q/S $(EXE).exe
