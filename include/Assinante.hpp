#pragma once
#ifndef _ASSINANTE_
#define _ASSINANTE_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <list>

using namespace std;

class Assinante: public Usuario
{
    private:
        list<Midia*> favoritos;

    public:
        Assinante();
        Assinante(string _nome, int codigo);
        ~Assinante();
        void imprimeFavoritos();
        void insereFavoritos(Midia *favorito);
        void removeFavorito();
        list<Midia*> getFavoritos();
        void setFavoritos(list<Midia*> favoritos);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
};

#endif
