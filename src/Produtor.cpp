#include "../include/Produtor.hpp"

Produtor::Produtor(){
    //
}

Produtor::Produtor(string _nome, int codigo){
    this->nome = _nome;
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

void Produtor::novoProduto(Midia* produto){
    this->produtosDesenvolvidos.push_back(produto);
}