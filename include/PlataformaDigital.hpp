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
#include "Aux.hpp"

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
        // Imprime código e nome do objeto no arquivo
        void imprimeNoArquivo(ofstream &outfile);

        pair<float, Midia::Genero*> generoMaisEscutado();

        /* Escrita de relatórios */
        // Lê arquivo midias.csv
        void carregaArquivoMidias(ifstream &infile);
        // Lê arquivo generos.csv
        void carregaArquivoGeneros(ifstream &infile);
        // Lê arquivo favoritos.csv
        void carregaArquivoFavoritos(ifstream &infile);
        // Lê arquivo usuarios.csv
        void carregaArquivoUsuarios(ifstream &infile);

        void imprimeGeneros();
        void imprimeUsuarios();
        void imprimeProdutores();

        /* Escrita de relatórios */
        // Retorna tempo total consumido pelos favoritos de todos os assinantes
        float tempoConsumido();
        void exportaBiblioteca();
        // Escreve arquivo 1-estatistica.txt
        void geraRelatorioEstatisticas();
        // Escreve arquivo 2-produtores.csv
        void geraRelatorioMidiasProdutores();
        // Escreve arquivo 3-favoritos.csv
        void geraRelatorioFavoritos();
        // Escreve arquivo 4-backup.txt
        void geraRelatorioBackup();

};

#endif
