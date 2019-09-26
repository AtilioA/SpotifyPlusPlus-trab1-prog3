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
    //
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