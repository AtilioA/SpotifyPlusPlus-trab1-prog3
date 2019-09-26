#include "../include/Assinante.hpp"

Assinante::Assinante(){
    //
}

Assinante::Assinante(string _nome){
    //
}

Assinante::~Assinante(){
    //
}

void Assinante::imprimeFavoritos(){
    //
}

void Assinante::insereFavoritos(Midia * favorito){
    //
}

void Assinante::removerFavorito(){
    //
}

vector<Midia*> Assinante::getFavoritos(){
    return this->favoritos;
}

void Assinante::setFavoritos(vector<Midia*> favoritos){
    this->favoritos = favoritos;
}

void Assinante::imprimeNoArquivo(ofstream &outfile){
    //
}

void Assinante::carregaArquivo(ifstream &infile){
    //
}
 