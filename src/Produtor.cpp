#include "../include/Produtor.hpp"

Produtor::Produtor(){
    //
}

Produtor::Produtor(string _nome, int codigo){
    this->nome = _nome;
}

void Produtor::criarProduto(){
    //
}

void Produtor::imprimeProdutosDesenvolvidos(){
    //
}

void Produtor::imprimeNoArquivo(ofstream &outfile){
    //
}

void Produtor::carregaArquivo(ifstream &infile){
    //
}

void Produtor::setProdutosDesenvolvidos(vector<Midia*> produtosDesenvolvidos){
    this->produtosDesenvolvidos = produtosDesenvolvidos;
}

vector<Midia*> Produtor::getProdutosDesenvolvidos(){
    return this->produtosDesenvolvidos;
}

string Produtor::getBiografia(){
    return this->biografia;
}

void Produtor::setBiografia(string biografia){
    this->biografia = biografia;
}
