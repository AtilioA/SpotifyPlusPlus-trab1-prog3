#include "../include/Produtor.hpp"

Produtor::Produtor()
{
    //
}

Produtor::Produtor(string _nome, int codigo)
{
    this->nome = _nome;
    this->codigo = codigo;
}

void Produtor::imprimeProdutosDesenvolvidos()
{
    //
}

void Produtor::imprimeNoArquivo(ofstream &outfile)
{
    outfile << this->getNome() << ";";
    this->produtosDesenvolvidos.sort(ordenarPorNome<Midia>);
    list<Midia *>::iterator it = this->produtosDesenvolvidos.begin();
    if(this->produtosDesenvolvidos.begin() != this->produtosDesenvolvidos.end()){
        outfile << (*it)->getNome();
    }
    for(advance(it, 1); it != this->produtosDesenvolvidos.end(); it++){
        outfile << ", " << (*it)->getNome();
    }
    outfile << "\n";
}

void Produtor::carregaArquivo(ifstream &infile)
{
    //
}

void Produtor::setProdutosDesenvolvidos(list<Midia *> produtosDesenvolvidos)
{
    this->produtosDesenvolvidos = produtosDesenvolvidos;
}

list<Midia *> Produtor::getProdutosDesenvolvidos()
{
    return this->produtosDesenvolvidos;
}

void Produtor::novoProduto(Midia *produto)
{
    this->produtosDesenvolvidos.push_back(produto);
}
