#pragma once
#ifndef _PODCAST_
#define _PODCAST_
#include "Midia.hpp"

using namespace std;

class Podcast : public Midia
{
    private:
        int qtdTemporadas;

    public:
        Podcast();
        Podcast(string nome, int codigo, Midia::Genero* gen, int qtdTemp, float duracao, int ano);

        int getQtdTemporadas();
        void setQtdTemporadas(int qtdTemporadas);
        int getTemporada();
        char getTipo();

        // Imprime código e nome do objeto no arquivo
        void imprimeNoArquivo(ofstream &outfile);
};

#endif
