#ifndef _MIDIA_
#define _MIDIA_
#include <iostream>
#include "Produtor.hpp"

class Produtor;

using namespace std;

class Midia{
    protected:
        string nome;
        int codigo;
        int duracao;
        int anoLancamento;
    public:
        static int qtdProdutos;
        Midia();
        Midia(string nome, bool explicito, string genero);
        static void imprimeQtdProdutos();
        virtual void imprimeInfoProduto() = 0;
        virtual void imprimeNoArquivo() = 0;

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
        string getNome();
        void setNome(string nome);
        Genero getGenero();
        void setGenero(Genero genero);
        Produtor* getProdutor();
        void setProdutor(Produtor* produtor);
        
    private:
        bool explicito;
        Genero genero;
        Produtor* produtor;
};

#endif