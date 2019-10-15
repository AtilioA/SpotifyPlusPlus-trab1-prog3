#ifndef _PODCASTER_
#define _PODCASTER_
#include <list>
#include "Produtor.hpp"
#include "Podcast.hpp"

using namespace std;

class Podcaster: public Produtor
{
    private:
        list<Podcast*> podcasts;

    public:
        Podcaster(string _nome, int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
        void inserirPodcast(Podcast* podcast);
        list<Podcast*>* getPodcasts();
};

#endif
