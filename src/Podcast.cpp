#include "../include/Podcast.hpp"

Podcast::Podcast()
{
}

Podcast::Podcast(string nome, int codigo, Midia::Genero *gen, int qtdTemp, float duracao) : Midia(nome, codigo, gen, duracao)
{
    this->qtdTemporadas = qtdTemp;
}

void Podcast::imprimeInfoProduto()
{
}

void Podcast::imprimeNoArquivo()
{
}

int Podcast::getQtdTemporadas()
{
    return this->qtdTemporadas;
}

void Podcast::setQtdTemporadas(int qtdTemporadas)
{
    this->qtdTemporadas = qtdTemporadas;
}
