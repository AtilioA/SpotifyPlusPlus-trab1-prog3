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
        void formataDuracao(string duracao);
        Album* album;

    public:
        Musica();
        Musica(string nome, int codigo, Midia::Genero* genero, float duracao, int ano);
        void setAnoLancamento(int anoLancamento);
        Album* getAlbum();
        void setAlbum(Album* album);
        void imprimeInfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
        char getTipo();
};

#endif
