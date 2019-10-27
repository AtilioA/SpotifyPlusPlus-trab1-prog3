#pragma once
#ifndef _ASSINANTE_
#define _ASSINANTE_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <list>

using namespace std;

class Assinante : public Usuario
{
    private:
        list<Midia*> favoritos;

    public:
        Assinante();
        Assinante(string _nome, int codigo);
        ~Assinante();

        void insereFavoritos(Midia *favorito);
        list<Midia*> getFavoritos();
        void setFavoritos(list<Midia*> favoritos);

        // Imprime código e nome do objeto no arquivo
        void imprimeNoArquivo(ofstream &outfile);
        // Calcula o tempo de duração das mídias de favoritos de um assinante
        float calculaTempoFavs();
};

#endif
