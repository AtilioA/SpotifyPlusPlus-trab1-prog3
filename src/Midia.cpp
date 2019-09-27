#include "../include/Midia.hpp"

Midia::Midia(){
    //
}

Midia::Midia(string nome, bool explicito, string genero){
    //
}

Midia::Genero::Genero(){
    //
}

Midia::Genero::Genero(string nome, string sigla){
    this->nome = nome;
    this->sigla = sigla;
}

string Midia::getNome(){
    return this->nome;
}

void Midia::setNome(string nome){
    this->nome = nome;
}

string Midia::Genero::getNome(){
    return this->nome;
}

void Midia::Genero::setNome(string nome){
    this->nome = nome;
}

string Midia::Genero::getSigla(){
    return this->sigla;
}

void Midia::Genero::setSigla(string sigla){
    this->sigla = sigla;
}

Midia::Genero Midia::getGenero(){
    return this->genero;
}

void Midia::setGenero(Midia::Genero genero){
    this->genero = genero;
}

Produtor* Midia::getProdutor(){
    return this->produtor;
}

void Midia::setProdutor(Produtor* produtor){
    this->produtor = produtor;
}
