#pragma once
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
        ~Podcaster();
        Podcaster(string _nome, int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
        void inserePodcast(Podcast* podcast);
        list<Podcast*>* getPodcasts();
};

#endif
