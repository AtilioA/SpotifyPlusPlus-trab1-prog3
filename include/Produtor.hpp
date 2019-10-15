#ifndef _PRODUTOR_
#define _PRODUTOR_
#include "Usuario.hpp"
#include "Midia.hpp"
#include <list>
#include <fstream>
#include <limits>

class Midia;

using namespace std;

class Produtor: public Usuario
{
    protected:
        list<Midia*> produtosDesenvolvidos;
        
    public:
        Produtor();
        Produtor(string _nome, int codigo);
        void imprimeProdutosDesenvolvidos();
        void setProdutosDesenvolvidos(list<Midia*> produtosDesenvolvidos);
        void novoProduto(Midia* produto);
        list<Midia*> getProdutosDesenvolvidos();
        virtual void imprimeNoArquivo(ofstream &outfile);
        virtual void carregaArquivo(ifstream &infile);
};

template <typename clss>
bool ordenarPorNome(clss* p1, clss* p2){
    if(p1->getNome().compare(p2->getNome()) < 0){
        return 1;
    }
    return 0;
};

#endif
