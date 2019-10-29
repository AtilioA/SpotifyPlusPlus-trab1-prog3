OBJ      := obj
SRC      := src
INC      := include
CXXFLAGS := -ggdb -g -Wall -Wextra -Ofast -std=c++17
EXE 	 := main
PROJETO  := tp1prog3-AtilioDadalto-TiagoSantos

main: $(OBJ)/utils.o $(OBJ)/Album.o $(OBJ)/Artista.o $(OBJ)/Assinante.o $(OBJ)/Midia.o $(OBJ)/Musica.o $(OBJ)/PlataformaDigital.o $(OBJ)/Podcast.o $(OBJ)/Podcaster.o $(OBJ)/Produtor.o $(OBJ)/Usuario.o $(OBJ)/$(PROJETO).o
	g++ $(OBJ)/*.o -o $(EXE) $(CXXFLAGS)

$(OBJ)/$(PROJETO).o: $(PROJETO).cpp
	g++ -c $(CXXFLAGS) $(PROJETO).cpp -o "$(OBJ)/$(PROJETO).o"

$(OBJ)/utils.o: $(SRC)/utils.cpp $(INC)/utils.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/utils.cpp" -o "$(OBJ)/utils.o"

$(OBJ)/Album.o: $(SRC)/Album.cpp $(INC)/Album.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/Album.cpp" -o "$(OBJ)/Album.o"

$(OBJ)/Artista.o: $(SRC)/Artista.cpp $(INC)/Artista.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/Artista.cpp" -o "$(OBJ)/Artista.o"

$(OBJ)/Assinante.o: $(SRC)/Assinante.cpp $(INC)/Assinante.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/Assinante.cpp" -o "$(OBJ)/Assinante.o"

$(OBJ)/Midia.o: $(SRC)/Midia.cpp $(INC)/Midia.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/Midia.cpp" -o "$(OBJ)/Midia.o"

$(OBJ)/Musica.o: $(SRC)/Musica.cpp $(INC)/Musica.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/Musica.cpp" -o "$(OBJ)/Musica.o"

$(OBJ)/Podcast.o: $(SRC)/Podcast.cpp $(INC)/Podcast.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/Podcast.cpp" -o "$(OBJ)/Podcast.o"

$(OBJ)/Podcaster.o: $(SRC)/Podcaster.cpp $(INC)/Podcaster.hpp
	g++ -c $(CXXFLAGS) $(SRC)/Podcaster.cpp -o "$(OBJ)/Podcaster.o"

$(OBJ)/Produtor.o: $(SRC)/Produtor.cpp $(INC)/Produtor.hpp
	g++ -c $(CXXFLAGS) $(SRC)/Produtor.cpp -o "$(OBJ)/Produtor.o"

$(OBJ)/Usuario.o: $(SRC)/Usuario.cpp $(INC)/Usuario.hpp
	g++ -c $(CXXFLAGS) $(SRC)/Usuario.cpp -o "$(OBJ)/Usuario.o"

$(OBJ)/PlataformaDigital.o: $(SRC)/PlataformaDigital.cpp $(INC)/PlataformaDigital.hpp
	g++ -c $(CXXFLAGS) "$(SRC)/PlataformaDigital.cpp" -o "$(OBJ)/PlataformaDigital.o"

run:
	./$(EXE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas.csv

runV:
	valgrind --leak-check=full ./$(EXE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas.csv

# Limpa objetos e o executável do programa (para Linux)
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)

# Entradas autorais
run_a1:
	./$(EXE) -u entradas_autorais/e1/usuarios.csv -f entradas_autorais/e1/favoritos.csv -g entradas_autorais/e1/generos.csv -m entradas_autorais/e1/midias.csv

run_a2:
	./$(EXE) -u entradas_autorais/e2/usuarios.csv -f entradas_autorais/e2/favoritos.csv -g entradas_autorais/e2/generos.csv -m entradas_autorais/e2/midias.csv
