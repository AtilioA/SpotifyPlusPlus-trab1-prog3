#ifndef _PODCAST_
#define _PODCAST_
#include "Midia.hpp"

using namespace std;

class Podcast: public Midia
{
    private:
        int qtdTemporadas;

    public:
        Podcast();
        Podcast(string nome, int codigo, Midia::Genero* gen, int qtdTemp, float duracao);
        int getQtdTemporadas();
        void setQtdTemporadas(int qtdTemporadas);
        void imprimeInfoProduto();
        void imprimeNoArquivo();
};

#endif
