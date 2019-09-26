#ifndef _PRODUTOR_
#define _PRODUTOR_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include <fstream>

using namespace std;

class Produtor: public Usuario{
    protected:
        string biografia;
        vector<Midia*> produtosDesenvolvidos;
    public:
        Produtor();
        Produtor(string _nome);
        void criarProduto();
        void imprimeProdutosDesenvolvidos();
        vector<Midia*> getProdutosDesenvolvidos();
        virtual void imprimeNoArquivo(ofstream &outfile);
        virtual void carregaArquivo(ifstream &infile);
};

#endif