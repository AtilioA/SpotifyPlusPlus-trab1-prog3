OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O3
EXE 	 := spotify==
PROJETO  := tp1prog3-AtilioDadalto-TiagoSantos

main: $(OBJ)/$(PROJETO).o
	g++ $(OBJ)/*.o -o $(EXE) $(CFLAGS)

$(OBJ)/$(PROJETO).o: $(PROJETO).cpp
	g++ -c $(CFLAGS) $(PROJETO).cpp -o "$(OBJ)/$(PROJETO).o"

# Limpa objetos e o executável do programa (para Linux)
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)

# Limpa objetos e o executável do programa (para Windows)
cleanW:
	del /F/Q/S "$(OBJ)\*.o"
	del /F/Q/S "$(EXE).exe"
