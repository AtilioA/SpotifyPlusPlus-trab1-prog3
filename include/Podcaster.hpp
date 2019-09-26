#ifndef _PODCASTER_
#define _PODCASTER_
#include "Produtor.hpp"

using namespace std;

class Podcaster: public Produtor{
    //relação de lançamento do podcast???
    public:
        Podcaster();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
};

#endif