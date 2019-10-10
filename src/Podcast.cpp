#include "../include/Podcast.hpp"

Podcast::Podcast(){

}

Podcast::Podcast(string nome, int codigo, Midia::Genero* gen, int qtdTemp): Midia(nome, codigo, gen){
    this->qtdTemporadas = qtdTemp;
}

void Podcast::imprimeInfoProduto(){

}

void Podcast::imprimeNoArquivo(){

}

int Podcast::getQtdTemporadas(){
   return this->qtdTemporadas; 
}

void Podcast::setQtdTemporadas(int qtdTemporadas){
    this->qtdTemporadas = qtdTemporadas;
}
