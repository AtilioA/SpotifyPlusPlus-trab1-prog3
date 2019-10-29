#include "../include/Produtor.hpp"

Produtor::Produtor()
{
    this->favoritado = 0;
}

Produtor::Produtor(string _nome, int codigo) : Usuario(_nome, codigo)
{
    this->favoritado = 0;
}

void Produtor::setProdutosDesenvolvidos(list<Midia *> produtosDesenvolvidos)
{
    this->produtosDesenvolvidos = produtosDesenvolvidos;
}

list<Midia *>* Produtor::getProdutosDesenvolvidos()
{
    return &(this->produtosDesenvolvidos);
}

void Produtor::novoProduto(Midia *produto)
{
    this->produtosDesenvolvidos.push_back(produto);
}

Produtor::~Produtor()
{
    this->produtosDesenvolvidos.clear();
}

void Produtor::imprimeNoArquivo(ofstream &outfile)
{
    outfile << this->getNome() << ";";

    this->produtosDesenvolvidos.sort(ordenaPorNome<Midia>);
    list<Midia *>::iterator it = this->produtosDesenvolvidos.begin();
    if (this->produtosDesenvolvidos.begin() != this->produtosDesenvolvidos.end())
    {
        outfile << (*it)->getNome();
    }
    for (advance(it, 1); it != this->produtosDesenvolvidos.end(); it++)
    {
        outfile << ", " << (*it)->getNome();
    }

    outfile << "\n";
}

int Produtor::getFavoritado()
{
    return this->favoritado;
}

void Produtor::adicionadoAosFavoritos()
{
    this->favoritado++;
}
