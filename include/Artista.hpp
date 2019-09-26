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
        Artista();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
};

#endif