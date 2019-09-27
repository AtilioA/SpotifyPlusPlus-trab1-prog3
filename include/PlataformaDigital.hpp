#ifndef _PLATAFORMA_DIGITAL_
#define _PLATAFORMA_DIGITAL_
#include <iostream>
#include <vector>
#include "Assinante.hpp"
#include "Midia.hpp"

using namespace std;

class PlataformaDigital{
    private:
        string nome;
        vector<Assinante*> assinantes;
        vector<Midia*> produtosCadastrados;
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
        vector<Midia*> getProdutosCadastrados();
        vector<Assinante*> getAssinantes();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
        void exportarBiblioteca();
        void gerarRelatorios();

        string getNome();
        void setNome(string nome);
        void setAssinantes(vector<Assinante*> assinantes);
        void setProdutosCadastrados(vector<Midia*> produtosCadastrados);
};

#endif