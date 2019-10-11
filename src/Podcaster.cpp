#include "../include/Podcaster.hpp"

Podcaster::Podcaster(string _nome, int codigo): Produtor(_nome, codigo){}

void Podcaster::imprimeNoArquivo(ofstream &outfile){
    //
}

void Podcaster::carregaArquivo(ifstream &infile){
    //
}

vector<Podcast*>* Podcaster::getPodcasts(){
    return &(this->podcasts);
}