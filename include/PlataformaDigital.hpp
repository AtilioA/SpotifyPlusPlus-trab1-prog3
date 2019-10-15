#ifndef _PLATAFORMA_DIGITAL_
#define _PLATAFORMA_DIGITAL_
#include <iostream>
#include <list>
#include <typeinfo>
#include <cstdlib>
#include "Produtor.hpp"
#include "Artista.hpp"
#include "Podcaster.hpp"
#include "Assinante.hpp"
#include "Midia.hpp"

using namespace std;

class PlataformaDigital
{
    private:
        string nome;
        list<Assinante*> assinantes;
        list<Midia*> produtosCadastrados;
        list<Produtor*> produtoresCadastrados;
        list<Midia::Genero*> generosCadastrados;

    public:
        PlataformaDigital();
        PlataformaDigital(string _nome);
        void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void inserirAssinante();
        void removerAssinante();
        int inserirProduto(Midia * novoProduto, string nomeProdutor);
        int selecionaAssinante();
        void inserirProdutoAssinante();
        list<Midia*> getProdutosCadastrados();
        list<Assinante*> getAssinantes();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivoMidias(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        void carregaArquivoFavoritos(ifstream &infile);
        void carregaArquivoUsuarios(ifstream &infile);
        void imprimeGeneros();
        void imprimeUsuarios();
        void imprimeProdutores();
        void exportarBiblioteca();
        void gerarRelatorios();

        string getNome();
        void setNome(string nome);
        void setAssinantes(list<Assinante*> assinantes);
        void setProdutosCadastrados(list<Midia*> produtosCadastrados);
};

#endif
