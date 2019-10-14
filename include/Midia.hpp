#ifndef _MIDIA_
#define _MIDIA_
#include <iostream>
#include "Produtor.hpp"
#include <vector>

class Produtor;

using namespace std;

class Midia
{
    protected:
        string nome;
        int codigo;
        int duracao;
        int anoLancamento;

    public:
        class Genero
        {
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

        static int qtdProdutos;
        Midia();
        Midia(string nome, int codigo, Genero *genero);
        static void imprimeQtdProdutos();
        virtual void imprimeInfoProduto() = 0;
        virtual void imprimeNoArquivo() = 0;
        int getCodigo();
        string getNome();
        void setNome(string nome);
        Genero *getGenero();
        void setGenero(Genero *genero);
        vector<Produtor *> getProdutor();
        void setProdutor(vector<Produtor *> produtor);

    private:
        bool explicito;
        Genero *genero;
        vector<Produtor *> produtor;
};

#endif
