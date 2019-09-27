#include "../include/Musica.hpp"

void Musica::formataDuracao(){
    //
}

Musica::Musica(){
    //
}

Musica::Musica(string nome, int clas, string genero, int duracao, int ano){
    //
}

void Musica::imprimeInfoProduto(){
    //
}

void Musica::imprimeNoArquivo(){
    //
}

void Musica::carregaArquivo(){
    //
}

void Musica::setDuracao(int duracao){
    this->duracao = duracao;
}

void Musica::setAnoLancamento(int anoLancamento){
    this->anoLancamento = anoLancamento;
}

int Musica::getAnoLancamento(){
    return this->anoLancamento;
}

int Musica::getDuracao(){
    return this->duracao;
}
