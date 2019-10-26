#include "../include/Podcaster.hpp"

Podcaster::Podcaster(string _nome, int codigo) : Produtor(_nome, codigo) {}

void Podcaster::imprimeNoArquivo(ofstream &outfile)
{
    outfile << this->getNome() << ";";

    this->produtosDesenvolvidos.sort(ordenaPorNome<Midia>);
    list<Midia *>::iterator it = this->produtosDesenvolvidos.begin();
    if (this->produtosDesenvolvidos.begin() != this->produtosDesenvolvidos.end())
    {
        outfile << (*it)->getNome();
    }
    for (advance(it, 1); it != this->produtosDesenvolvidos.end(); it++)
    {
        outfile << ", " << (*it)->getNome();
    }

    outfile << "\n";
}

void Podcaster::carregaArquivo(ifstream &infile)
{
    //
}

list<Podcast *> *Podcaster::getPodcasts()
{
    return &(this->podcasts);
}

void Podcaster::inserePodcast(Podcast *podcast)
{
    this->podcasts.push_back(podcast);
}

Podcaster::~Podcaster()
{
    this->podcasts.clear();
}
