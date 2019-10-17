#ifndef _MUSICA_
#define _MUSICA_
#include "Midia.hpp"
#include "Album.hpp"

class Album;

using namespace std;

class Musica: public Midia
{
    private:
        void formataDuracao(string duracao);
        Album* album;

    public:
        Musica();
        Musica(string nome, int codigo, Midia::Genero* genero, float duracao, int ano);
        void setAnoLancamento(int anoLancamento);
        int getAnoLancamento();
        void imprimeInfoProduto();
        void imprimeNoArquivo();
};

#endif
