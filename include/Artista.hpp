#ifndef _ARTISTA_
#define _ARTISTA_
#include "Produtor.hpp"

using namespace std;

class Artista: public Produtor{
    //relação de lançamento do album???
    public:
        Artista();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
};

#endif