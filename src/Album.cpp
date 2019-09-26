#include "../include/Album.hpp"

Album::Album(){
    //
}

Album::Album(string nome, int duracao, int ano, int qtd){
    //
}

void Album::imprimeNoArquivo(ofstream &outfile){
    //
}

void Album::setQtdMusicas(int qtdMusicas) {
    this->qtdMusicas = qtdMusicas;
}

int Album::getQtdMusicas() {
    return qtdMusicas;
}

void Album::setNome(string nome) {
    this->nome = nome;
}

string Album::getNome() {
    return nome;
}

void Album::setDuracao(int duracao) {
    this->duracao = duracao;
}

int Album::getDuracao() {
    return duracao;
}

void Album::setAnoLancamento(int anoLancamento) {
    this->anoLancamento = anoLancamento;
}

int Album::getAnoLancamento() {
    return anoLancamento;
}

void Album::setMusicas(vector<Musica*> musicas){
    this->musicas = musicas;
}

vector<Musica*> Album::getMusica(){
    return this->musicas;
}