#ifndef _MIDIA_
#define _MIDIA_
#include <iostream>
#include "Produtor.hpp"

class Produtor;

using namespace std;

class Midia{
    protected:
        string nome;
    public:
        static int qtdProdutos;
        string getNome();
        void setNome(string nome);
        Midia();
        Midia(string nome, bool explicito, string genero);
        static void imprimeQtdProdutos();
        virtual void imprimeInfoProduto() = 0;
        virtual void imprimeNoArquivo() = 0;
        virtual void carregaArquivo() = 0;

        class Genero{
            private:
                string sigla;
                string nome;
            public:
                string getNome();
                string getSigla();
                void setNome(string nome);
                void setSigla(string sigla);
                Genero();
                Genero(string nome, string sigla);
        };
        
    private:
        bool explicito;
        Genero genero;
        Produtor* produtor;
};

#endif