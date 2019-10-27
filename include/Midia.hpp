#pragma once
#ifndef _MIDIA_
#define _MIDIA_
#include <iostream>
#include "Produtor.hpp"
#include <list>

class Produtor;

using namespace std;

class Midia
{
    protected:
        string nome;
        int codigo;
        float duracao;
        int anoLancamento;
        list<Produtor *> produtor;
        int favoritado;

    public:
        class Genero
        {
            private:
                string sigla;
                string nome;
                list<Midia*> midias;
                int qtdMidias;
                int favoritado;
                float escutado;
            public:
                Genero();
                Genero(string nome, string sigla);
                
                string getNome();
                string getSigla();
                int getQtdMidias();
                float tempoGenero();
                void favoritadoPorUser(float duracao);
                int getFavoritado();
                float getEscutado();
                void setNome(string nome);
                void setSigla(string sigla);
                void adicionaMidia(Midia* midia);
        };

        static int qtdProdutos;
        Midia();
        Midia(string nome, int codigo, Genero *genero, float duracao, int ano);
        virtual ~Midia() = 0;

        int getCodigo();
        string getNome();
        void setNome(string nome);
        Genero *getGenero();
        void setGenero(Genero *genero);
        list<Produtor *> getProdutor();
        float getDuracao();
        void setDuracao(float duracao);
        void setProdutor(list<Produtor *> produtor);
        void adicionaProdutor(Produtor* produtor);
        int getAnoLancamento();

        void adicionadoAosFavs();
        int getFavoritado();

        static void imprimeQtdProdutos();
        virtual void imprimeInfoProduto() = 0;
        // Imprime código e nome do objeto no arquivo
        virtual void imprimeNoArquivo(ofstream &outfile) = 0;
        virtual char getTipo() = 0;

    private:
        bool explicito;
        Genero *genero;
};

#endif
