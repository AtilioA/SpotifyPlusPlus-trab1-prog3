#pragma once
#ifndef _ARTISTA_
#define _ARTISTA_
#include <list>
#include "Produtor.hpp"
#include "Album.hpp"
#include "utils.hpp"

using namespace std;

class Artista : public Produtor
{
    private:
        list<Album*> albuns;

    public:
        Artista(string _nome, int codigo);
        ~Artista();

        void setAlbuns(list<Album*> albuns);
        void insereAlbum(Album* album);
        void insereMusica(Musica* musica);
        list<Album*>* getAlbuns();

        void imprimeNoArquivo(ofstream &outfile);
        // Retorna o álbum cujo nome é a string de entrada ou NULL se não houver
        Album* procuraAlbum(string album);
};

#endif
