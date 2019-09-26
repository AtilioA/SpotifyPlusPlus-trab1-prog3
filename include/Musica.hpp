#ifndef _MUSICA_
#define _MUSICA_
#include "Midia.hpp"

using namespace std;

class Musica: public Midia{
    private:
        int duracao;
        int anoLancamento;
        void formataDuracao();
    public:
        Musica();
        Musica(string nome, int clas, string genero, int duracao, int ano);
        void imprimeInfoProduto();
        void imprimeNoArquivo();
        void carregaArquivo();
};

#endif