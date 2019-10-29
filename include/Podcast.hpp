#pragma once
#ifndef _PODCAST_
#define _PODCAST_
#include "Midia.hpp"
#include "Podcaster.hpp"

using namespace std;

class Podcast : public Midia
{
    private:
        int qtdTemporadas;

    public:
        Podcast();
        Podcast(string nome, int codigo, Midia::Genero* gen, int qtdTemp, float duracao, int ano);
        ~Podcast();
        int getQtdTemporadas();
        void setQtdTemporadas(int qtdTemporadas);
        int getTemporada();
        char getTipo();

        void imprimeNoArquivo(ofstream &outfile);
};

#endif
