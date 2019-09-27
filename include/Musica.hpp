#ifndef _MUSICA_
#define _MUSICA_
#include "Midia.hpp"
#include "Album.hpp"

class Album;

using namespace std;

class Musica: public Midia{
    private:
        int duracao;
        int anoLancamento;
        void formataDuracao();
        Album* album;
    public:
        Musica();
        Musica(string nome, int clas, string genero, int duracao, int ano);
        void setDuracao(int duracao);
        void setAnoLancamento(int anoLancamento);
        int getAnoLancamento();
        int getDuracao();
        void imprimeInfoProduto();
        void imprimeNoArquivo();
        void carregaArquivo();
};

#endif