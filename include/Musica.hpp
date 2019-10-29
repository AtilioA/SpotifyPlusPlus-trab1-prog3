#pragma once
#ifndef _MUSICA_
#define _MUSICA_
#include "Midia.hpp"
#include "Album.hpp"

class Album;

using namespace std;

class Musica : public Midia
{
    private:
        Album* album;

    public:
        Musica();
        Musica(string nome, int codigo, Midia::Genero* genero, float duracao, int ano);
        ~Musica();
        void setAnoLancamento(int anoLancamento);
        Album* getAlbum();
        void setAlbum(Album* album);
        char getTipo();

        void imprimeNoArquivo(ofstream &outfile);
};

#endif
