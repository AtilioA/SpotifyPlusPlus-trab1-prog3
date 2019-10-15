#include "../include/Midia.hpp"

Midia::Midia()
{
    Midia::qtdProdutos++;
}

Midia::Midia(string nome, int codigo, Midia::Genero *genero)
{
    this->nome = nome;
    this->codigo = codigo;
    this->genero = genero;
    Midia::qtdProdutos++;
}

Midia::Genero::Genero()
{
    //
}

Midia::Genero::Genero(string nome, string sigla)
{
    this->nome = nome;
    this->sigla = sigla;
}

int Midia::getCodigo()
{
    return this->codigo;
}

string Midia::getNome()
{
    return this->nome;
}

void Midia::setNome(string nome)
{
    this->nome = nome;
}

string Midia::Genero::getNome()
{
    return this->nome;
}

void Midia::Genero::setNome(string nome)
{
    this->nome = nome;
}

string Midia::Genero::getSigla()
{
    return this->sigla;
}

void Midia::Genero::setSigla(string sigla)
{
    this->sigla = sigla;
}

Midia::Genero *Midia::getGenero()
{
    return this->genero;
}

void Midia::setGenero(Midia::Genero *genero)
{
    this->genero = genero;
}

list<Produtor *> Midia::getProdutor()
{
    return this->produtor;
}

void Midia::setProdutor(list<Produtor *> produtor)
{
    this->produtor = produtor;
}

void Midia::adicionarProdutor(Produtor* produtor){
    this->produtor.push_back(produtor);
}

void Midia::Genero::adicionarMidia(Midia* midia){
    this->midias.push_back(midia);
}

void Midia::setDuracao(float duracao)
{
    this->duracao = duracao;
}

float Midia::getDuracao()
{
    return this->duracao;
}