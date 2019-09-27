#ifndef _ALBUM_
#define _ALBUM_
#include "Musica.hpp"
#include <vector>

class Musica;

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
        void setQtdMusicas(int qtdMusicas);
        int getQtdMusicas();
        void setNome(string nome);
        string getNome();
        void setDuracao(int duracao);
        int getDuracao();
        void setAnoLancamento(int anoLancamento);
        int getAnoLancamento();
        void setMusicas(vector<Musica*> musicas);
        vector<Musica*> getMusica();
};


#endif