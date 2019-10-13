#include "../include/Usuario.hpp"

void Usuario::setNome(string nome){
    this->nome = nome;
}

string Usuario::getNome(){
    return this->nome;
}

int Usuario::getCodigo(){
    return this->codigo;
}

void Usuario::setCodigo(int codigo)
{
    this->codigo = codigo;
}
