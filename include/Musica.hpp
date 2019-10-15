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
        Musica(string nome, int codigo, Midia::Genero* genero, int duracao, int ano);
        void setDuracao(float duracao);
        void setAnoLancamento(int anoLancamento);
        int getAnoLancamento();
        float getDuracao();
        void imprimeInfoProduto();
        void imprimeNoArquivo();
};

#endif
