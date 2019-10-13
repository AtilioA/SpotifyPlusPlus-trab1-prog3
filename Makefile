CXX		  	:= g++
CXX_FLAGS 	:= -ggdb -g -Wall # -Wextra -std=c++17
SRC			:= src
INCLUDE		:= include
OBJ 		:= obj
EXECUTABLE	:= main

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

run:
	$(EXECUTABLE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas_corrigidas.csv

run_a:
	$(EXECUTABLE) -u entradas_autorais/usuarios1.csv -f entradas_autorais/favoritos1.csv -g entradas_autorais/generos1.csv -m entradas_autorais/midias1.csv

run_e:
	$(EXECUTABLE) -u entradas_autorais/usuarios_e.csv -f entradas_autorais/favoritos_e.csv -g entradas_autorais/generos_e.csv -m entradas_autorais/midias_e.csv

warns: $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -Wextra -I$(INCLUDE) $^ -o $@

clean:
	-rm $(OBJ)/*.o
	# make

cleanW:
	del /S /F "*.o"
	del /S /F "main.exe"

# valgrind ./a.out -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas_corrigidas.csv
