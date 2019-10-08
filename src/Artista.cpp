#include "../include/Artista.hpp"

Artista::Artista(string _nome, int codigo){
    this->nome = _nome;
    this->codigo = codigo;
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
