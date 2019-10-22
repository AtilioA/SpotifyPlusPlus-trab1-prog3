OBJ      := obj
SRC      := src
INC      := include
CXXFLAGS := -ggdb -g -Wall -std=c++17
EXE 	 := main
PROJETO  := tp1prog3-AtilioDadalto-TiagoSantos

main: $(OBJ)/Album.o $(OBJ)/Artista.o $(OBJ)/Assinante.o $(OBJ)/Midia.o $(OBJ)/Musica.o $(OBJ)/PlataformaDigital.o $(OBJ)/Podcast.o $(OBJ)/Podcaster.o $(OBJ)/Produtor.o $(OBJ)/Usuario.o $(OBJ)/$(PROJETO).o
	g++ $(OBJ)/*.o -o $(EXE) $(CXXFLAGS)

$(OBJ)/$(PROJETO).o: $(PROJETO).cpp
	g++ -c $(CXXFLAGS) $(PROJETO).cpp -o "$(OBJ)/$(PROJETO).o"

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

# RECEITINHAS PARA TESTES
# Entradas autorais
run_a1:
	./$(EXE) -u entradas_autorais/usuarios1.csv -f entradas_autorais/favoritos1.csv -g entradas_autorais/generos1.csv -m entradas_autorais/midias1.csv

run_a2:
	./$(EXE) -u entradas_autorais/usuarios2.csv -f entradas_autorais/favoritos2.csv -g entradas_autorais/generos2.csv -m entradas_autorais/midias2.csv

run_p:
	./$(EXE) -u entradas_autorais/python/usuarios_python.csv -f entradas_autorais/python/favoritos_python.csv -g entradas_autorais/python/generos_python.csv -m entradas_autorais/python/midias_python.csv

run_pV:
	valgrind --leak-check=full ./$(EXE) -u entradas_autorais/python/usuarios_python.csv -f entradas_autorais/python/favoritos_python.csv -g entradas_autorais/python/generos_python.csv -m entradas_autorais/python/midias_python.csv


# Entradas com erros
# Erro 1
run_e11:
	./$(EXE) -u entradas/naoexiste.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas.csv

run_e12:
	./$(EXE) -u entradas/usuarios.csv -f entradas/naoexiste.csv -g entradas/generos.csv -m entradas/midias_corrigidas.csv

run_e13:
	./$(EXE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/naoexiste.csv -m entradas/midias_corrigidas.csv

run_e14:
	./$(EXE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/naoexiste.csv

# Erro 2
run_e21:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e21.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e21.csv

run_e22:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e22.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e22.csv

run_e23:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e23.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e23.csv

run_e24:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e24.csv

run_e25:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e25.csv

run_e26:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e26.csv

run_e27:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e27.csv

run_e28:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e28.csv

run_e29:
	./$(EXE) -u entradas_autorais/testes_erro2/usuarios_e2.csv -f entradas_autorais/testes_erro2/favoritos_e2.csv -g entradas_autorais/testes_erro2/generos_e2.csv -m entradas_autorais/testes_erro2/midias_e29.csv


# Erro 3
# Tipo de usuário sem correspondente (Não é A ou P ou U)
run_e31: # (na verdade é erro de formatação?)
	./$(EXE) -u entradas_autorais/testes_erro3/usuarios_e31.csv -f entradas_autorais/testes_erro3/favoritos_e31.csv -g entradas_autorais/testes_erro3/generos_e31.csv -m entradas_autorais/testes_erro3/midias_e31.csv

# Mídia sem sigla de gênero correspondente
run_e32:
	./$(EXE) -u entradas_autorais/testes_erro3/usuarios_e32.csv -f entradas_autorais/testes_erro3/favoritos_e32.csv -g entradas_autorais/testes_erro3/generos_e32.csv -m entradas_autorais/testes_erro3/midias_e32.csv

# Mídia sem tipo correspondente
run_e33:
	./$(EXE) -u entradas_autorais/testes_erro3/usuarios_e33.csv -f entradas_autorais/testes_erro3/favoritos_e33.csv -g entradas_autorais/testes_erro3/generos_e33.csv -m entradas_autorais/testes_erro3/midias_e33.csv

# Mídia sem código de produtor correspondente
run_e34:
	./$(EXE) -u entradas_autorais/testes_erro3/usuarios_e34.csv -f entradas_autorais/testes_erro3/favoritos_e34.csv -g entradas_autorais/testes_erro3/generos_e34.csv -m entradas_autorais/testes_erro3/midias_e34.csv

# Favorito sem mídia correspondente
run_e35:
	./$(EXE) -u entradas_autorais/testes_erro3/usuarios_e35.csv -f entradas_autorais/testes_erro3/favoritos_e35.csv -g entradas_autorais/testes_erro3/generos_e35.csv -m entradas_autorais/testes_erro3/midias_e35.csv

warns: $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -Wextra -I$(INCLUDE) $^ -o $@

# Limpa objetos e o executável do programa (para Linux)
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)

# Limpa objetos e o executável do programa (para Windows)
cleanW:
	del /F/Q/S "$(OBJ)\*.o"
	del /F/Q/S "$(EXE).exe"
