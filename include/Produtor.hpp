#pragma once
#ifndef _PRODUTOR_
#define _PRODUTOR_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <list>
#include <fstream>
#include <limits>

class Midia;

using namespace std;

class Produtor : public Usuario
{
    protected:
        list<Midia*> produtosDesenvolvidos;

    public:
        Produtor();
        Produtor(string _nome, int codigo);
        ~Produtor();
        void imprimeProdutosDesenvolvidos();
        void setProdutosDesenvolvidos(list<Midia*> produtosDesenvolvidos);
        void novoProduto(Midia* produto);
        list<Midia*> getProdutosDesenvolvidos();
        virtual void imprimeNoArquivo(ofstream &outfile);
        virtual void carregaArquivo(ifstream &infile);
};

template <typename clss>
bool ordenaPorNome(clss *prod1, clss *prod2)
{
    if (prod1->getNome().compare(prod2->getNome()) < 0)
    {
        return 1;
    }
    return 0;
};

#endif
