#include "../include/PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital(){
    //
}

PlataformaDigital::PlataformaDigital(string _nome){
    //
}

void PlataformaDigital::imprimeProdutos(string genero){
    //
}

void PlataformaDigital::imprimeAssinantes(){
    //
}

void PlataformaDigital::inserirAssinante(){
    //
}

void PlataformaDigital::removerAssinante(){
    //
}

int PlataformaDigital::inserirProduto(Midia * novoProduto, string nomeProdutor){
    //
}

int PlataformaDigital::selecionaAssinante(){
    //
}

void PlataformaDigital::inserirProdutoAssinante(){
    //
}

vector<Midia*> PlataformaDigital::getProdutosCadastrados(){
    return this->produtosCadastrados;
}

vector<Assinante*> PlataformaDigital::getAssinantes(){
    return this->assinantes;
}

void PlataformaDigital::imprimeNoArquivo(ofstream &outfile){
    //
}

void PlataformaDigital::carregaArquivo(ifstream &infile){
    //
}

void PlataformaDigital::exportarBiblioteca(){
    //
}

void PlataformaDigital::gerarRelatorios(){
    //
}

string PlataformaDigital::getNome(){
    return this->nome;
}

void PlataformaDigital::setNome(string nome){
    this->nome = nome;
}

void PlataformaDigital::setAssinantes(vector<Assinante*> assinantes){
    this->assinantes = assinantes;
}

void PlataformaDigital::setProdutosCadastrados(vector<Midia*> produtosCadastrados){
    this->produtosCadastrados = produtosCadastrados;
}
