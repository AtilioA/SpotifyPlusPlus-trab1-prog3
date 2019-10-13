CXX		  	:= g++
CXX_FLAGS 	:= -ggdb -g # -Wall -Wextra -std=c++17
CPP17_FLAGS := -std=c++17
SRC			:= src
INCLUDE		:= include
OBJ 		:= obj
EXECUTABLE	:= main

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

run:
	$(EXECUTABLE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas_corrigidas.csv

c17: $(EXECUTABLE)
	$(CXX) $(CXX_FLAGS) -std=c++17 -I$(INCLUDE) $^ -o $@

warns: $(EXECUTABLE)
	$(CXX) $(CXX_FLAGS) -Wall -Wextra -I$(INCLUDE) $^ -o $@

clean:
	-rm $(OBJ)/*.o
	# make

cleanW:
	del /S /F "*.o"
	del /S /F "main.exe"

# valgrind ./a.out -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas_corrigidas.csv
