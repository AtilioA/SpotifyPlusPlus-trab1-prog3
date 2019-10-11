CXX		  	:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb -g #-Wall -Wextra

SRC			:= src
INCLUDE		:= include
OBJ 		:= obj

LIBRARIES	:=
EXECUTABLE	:= main

all: $(EXECUTABLE)

# valgrind ./a.out -u entradas/usuarios\ copy.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas_corrigidas.csv

$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

run: clean all
	clean
	$(EXECUTABLE)

clean:
	# -rm $(OBJ)/*
	make
