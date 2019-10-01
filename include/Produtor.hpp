#ifndef _PRODUTOR_
#define _PRODUTOR_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include <fstream>

class Midia;

using namespace std;

class Produtor: public Usuario{
    protected:
        string biografia;
        vector<Midia*> produtosDesenvolvidos;
    public:
        Produtor();
        Produtor(string _nome, int codigo);
        void criarProduto();
        void imprimeProdutosDesenvolvidos();
        void setProdutosDesenvolvidos(vector<Midia*> produtosDesenvolvidos);
        vector<Midia*> getProdutosDesenvolvidos();
        string getBiografia();
        void setBiografia(string biografia);
        virtual void imprimeNoArquivo(ofstream &outfile);
        virtual void carregaArquivo(ifstream &infile);
};

#endif