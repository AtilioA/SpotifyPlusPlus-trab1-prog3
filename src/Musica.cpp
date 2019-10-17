#include "../include/Musica.hpp"

void Musica::formataDuracao(string duracao)
{
    //this->duracao recebe uma versão formatada da string
}

Musica::Musica()
{
    //
}

Musica::Musica(string nome, int codigo, Midia::Genero *genero, float duracao, int ano) : Midia(nome, codigo, genero, duracao)
{
    this->anoLancamento = ano;
}

void Musica::imprimeInfoProduto()
{
    //
}

void Musica::imprimeNoArquivo()
{
    //
}

void Musica::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

int Musica::getAnoLancamento()
{
    return this->anoLancamento;
}

