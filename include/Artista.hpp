#ifndef _ARTISTA_
#define _ARTISTA_
#include <vector>
#include "Produtor.hpp"
#include "Album.hpp"

using namespace std;

class Artista: public Produtor{
    private:
        vector<Album*> albuns;
    public:
        Artista(string _nome, int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
        void setAlbuns(vector<Album*> albuns);
        vector<Album*>* getAlbuns();
};

#endif