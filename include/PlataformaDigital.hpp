#pragma once
#ifndef _PLATAFORMA_DIGITAL_
#define _PLATAFORMA_DIGITAL_
#include <iostream>
#include <list>
#include <sstream>
#include <cstdlib>
#include "Produtor.hpp"
#include "Artista.hpp"
#include "Podcaster.hpp"
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Album.hpp"

using namespace std;

class PlataformaDigital
{
    private:
        string nome;
        list<Assinante*> assinantes;
        list<Midia*> produtosCadastrados;
        list<Produtor*> produtoresCadastrados;
        list<Midia::Genero*> generosCadastrados;
        list<Album*> albunsCadastrados;

    public:
        PlataformaDigital();
        PlataformaDigital(string _nome);
        ~PlataformaDigital();
        string getNome();
        void setNome(string nome);
        void setAssinantes(list<Assinante*> assinantes);
        void setProdutosCadastrados(list<Midia*> produtosCadastrados);
        list<Midia*> getProdutosCadastrados();
        list<Assinante*> getAssinantes();

        void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void insereAssinante();
        void removeAssinante();
        int insereProduto(Midia * novoProduto, string nomeProdutor);
        int selecionaAssinante();
        void insereProdutoAssinante();
        void imprimeNoArquivo(ofstream &outfile);

        void carregaArquivoMidias(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        void carregaArquivoFavoritos(ifstream &infile);
        void carregaArquivoUsuarios(ifstream &infile);

        void imprimeGeneros();
        void imprimeUsuarios();
        void imprimeProdutores();

        void exportaBiblioteca();
        void geraRelatorios();
        void geraRelatorioEstatisticas();
        void geraRelatorioMidiasProdutores();

        void geraRelatorioFavoritos();
        void geraRelatorioBackup();

        float tempoConsumido();
};

#endif
