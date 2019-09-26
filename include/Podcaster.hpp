#ifndef _PODCASTER_
#define _PODCASTER_
#include <vector>
#include "Produtor.hpp"
#include "Podcast.hpp"

using namespace std;

class Podcaster: public Produtor{
    private:
        vector<Podcast*> podcasts;
    public:
        Podcaster();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
};

#endif