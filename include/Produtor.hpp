#ifndef _PRODUTOR_
#define _PRODUTOR_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include <fstream>
#include <limits>

class Midia;

using namespace std;

class Produtor: public Usuario
{
    protected:
        vector<Midia*> produtosDesenvolvidos;
        
    public:
        Produtor();
        Produtor(string _nome, int codigo);
        void imprimeProdutosDesenvolvidos();
        void setProdutosDesenvolvidos(vector<Midia*> produtosDesenvolvidos);
        void novoProduto(Midia* produto);
        vector<Midia*> getProdutosDesenvolvidos();
        virtual void imprimeNoArquivo(ofstream &outfile);
        virtual void carregaArquivo(ifstream &infile);
};

#endif
