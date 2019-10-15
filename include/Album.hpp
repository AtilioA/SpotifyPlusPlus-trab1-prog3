#ifndef _ALBUM_
#define _ALBUM_
#include "Musica.hpp"
#include <list>

class Musica;

using namespace std;

class Album
{
    private:
        int anoLancamento;
        float duracao;
        string nome;
        int qtdMusicas;
        list<Musica*> musicas;

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
        void setMusicas(list<Musica*> musicas);
        list<Musica*> getMusica();
        void adicionarMusica(Musica* musica);
};


#endif
