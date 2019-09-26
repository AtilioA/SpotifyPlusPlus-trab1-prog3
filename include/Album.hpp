#ifndef _ALBUM_
#define _ALBUM_
#include "Musica.hpp"
#include <vector>

using namespace std;

class Album{
    private:
        int anoLancamento;
        int duracao;
        string nome;
        int qtdMusicas;
        vector<Musica*> musicas;
    public:
        Album();
        Album(string nome, int duracao, int ano, int qtd);
        void imprimeNoArquivo(ofstream &outfiles);
};

#endif