#pragma once
#ifndef _ALBUM_
#define _ALBUM_
#include "Musica.hpp"
#include <list>

class Musica;

using namespace std;

class Album
{
    private:
        int anoLancamento;
        float duracao;
        string nome;
        int qtdMusicas;
        int codigo;
        list<Musica*> musicas;

    public:
        Album();
        Album(string nome, int codigo, float duracao, int ano, int qtd);
        ~Album();

        void setQtdMusicas(int qtdMusicas);
        int getQtdMusicas();
        void setNome(string nome);
        string getNome();
        int getCodigo();
        list<Musica*> *getMusicas();
        void setCodigo(int codigo);
        void setDuracao(int duracao);
        int getDuracao();
        void setAnoLancamento(int anoLancamento);
        int getAnoLancamento();
        void setMusicas(list<Musica*> musicas);
        void adicionaMusica(Musica* musica);
};


#endif
