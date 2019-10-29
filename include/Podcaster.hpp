#pragma once
#ifndef _PODCASTER_
#define _PODCASTER_
#include <list>
#include "Produtor.hpp"
#include "Podcast.hpp"
#include "utils.hpp"

using namespace std;
class Podcast;

class Podcaster : public Produtor
{
    private:
        list<Podcast*> podcasts;

    public:
        Podcaster(string _nome, int codigo);
        ~Podcaster();

        void inserePodcast(Podcast* podcast);
        list<Podcast*>* getPodcasts();

        void imprimeNoArquivo(ofstream &outfile);
};

#endif
