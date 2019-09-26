#include "../include/Artista.hpp"

Artista::Artista(){
    //
}

void Artista::imprimeNoArquivo(ofstream &outfile){
    //
}

void Artista::carregaArquivo(ifstream &infile){
    //
}

void Artista::setAlbuns(vector<Album*> albuns){
    this->albuns = albuns;
}

vector<Album*> Artista::getAlbuns(){
    return this->albuns;
}
