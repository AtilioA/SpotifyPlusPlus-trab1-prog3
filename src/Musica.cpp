#include "../include/Musica.hpp"

void Musica::formataDuracao(string duracao){
    //this->duracao recebe uma versão formatada da string
}

Musica::Musica(){
    //
}

Musica::Musica(string nome, int clas, string genero, string duracao, int ano){
    this->nome = nome;
    Midia::Genero gen;
    gen.setNome(genero);
    this->setGenero(gen);
    formataDuracao(duracao);
    this->anoLancamento = ano;
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
