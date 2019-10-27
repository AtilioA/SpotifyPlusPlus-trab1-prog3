#pragma once
#ifndef _PRODUTOR_
#define _PRODUTOR_
#include <list>
#include <fstream>
#include <limits>
#include "Usuario.hpp"
#include "Midia.hpp"
#include "utils.hpp"

class Midia;

using namespace std;

class Produtor : public Usuario
{
    protected:
        list<Midia*> produtosDesenvolvidos;
        int favoritado;

    public:
        Produtor();
        Produtor(string _nome, int codigo);
        virtual ~Produtor() = 0;

        void setProdutosDesenvolvidos(list<Midia*> produtosDesenvolvidos);
        void novoProduto(Midia* produto);
        list<Midia*> getProdutosDesenvolvidos();

        int getFavoritado();
        void adicionadoAosFavoritos();
        // Imprime código e nome do objeto no arquivo
        virtual void imprimeNoArquivo(ofstream &outfile);
};

#endif
