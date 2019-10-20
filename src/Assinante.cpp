#include "../include/Assinante.hpp"

Assinante::Assinante()
{
    //
}

Assinante::Assinante(string _nome, int codigo): Usuario(_nome, codigo)
{
}


Assinante::~Assinante()
{
    //
}

void Assinante::imprimeFavoritos()
{
    //
}

void Assinante::insereFavoritos(Midia *favorito)
{
    this->favoritos.push_back(favorito);
}

void Assinante::removeFavorito()
{
    //
}

list<Midia *> Assinante::getFavoritos()
{
    return this->favoritos;
}

void Assinante::setFavoritos(list<Midia *> favoritos)
{
    this->favoritos = favoritos;
}

void Assinante::imprimeNoArquivo(ofstream &outfile)
{
    //
}

void Assinante::carregaArquivo(ifstream &infile)
{
    //
}
