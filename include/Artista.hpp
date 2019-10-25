#pragma once
#ifndef _ARTISTA_
#define _ARTISTA_
#include <list>
#include "Produtor.hpp"
#include "Album.hpp"

using namespace std;

class Artista : public Produtor
{
    private:
        list<Album*> albuns;

    public:
        ~Artista();
        Artista(string _nome, int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
        void setAlbuns(list<Album*> albuns);
        void insereAlbum(Album* album);
        void insereMusica(Musica* musica);
        Album* procuraAlbum(string album);
        list<Album*>* getAlbuns();
};

#endif
