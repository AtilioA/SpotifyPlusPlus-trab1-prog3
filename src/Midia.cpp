#include "../include/Midia.hpp"

Midia::Midia()
{
    Midia::qtdProdutos++;
}

Midia::~Midia()
{
    this->favoritado = 0;
    for(Produtor* it: this->produtor){
        it->getProdutosDesenvolvidos()->remove(this);
    }
}

Midia::Midia(string nome, int codigo, Midia::Genero *genero, float duracao, int ano)
{
    this->anoLancamento = ano;
    this->duracao = duracao;
    this->nome = nome;
    this->codigo = codigo;
    this->genero = genero;
    this->favoritado = 0;
    Midia::qtdProdutos++;
}

Midia::Genero::Genero()
{
    this->qtdMidias = 0;
    this->favoritado = 0;
    this->escutado = 0;
}

Midia::Genero::Genero(string nome, string sigla)
{
    this->nome = nome;
    this->sigla = sigla;
    this->qtdMidias = 0;
    this->favoritado = 0;
    this->escutado = 0;
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

void Midia::adicionaProdutor(Produtor *produtor)
{
    this->produtor.push_back(produtor);
}

void Midia::Genero::adicionaMidia(Midia *midia)
{
    this->qtdMidias++;
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

int Midia::getAnoLancamento()
{
    return this->anoLancamento;
}

int Midia::Genero::getQtdMidias()
{
    return this->qtdMidias;
}

float Midia::Genero::tempoGenero()
{
    float sum = 0;
    for (Midia *it : this->midias)
    {
        sum += it->getDuracao();
    }
    return sum;
}

void Midia::Genero::favoritadoPorUser(float duracao)
{
    this->favoritado++;
    this->escutado += duracao;
}

int Midia::Genero::getFavoritado()
{
    return this->favoritado;
}

float Midia::Genero::getEscutado()
{
    return this->escutado;
}

void Midia::adicionadoAosFavs()
{
    this->favoritado++;
    for(Produtor* it: this->produtor){
        it->adicionadoAosFavoritos();
    }
}

int Midia::getFavoritado()
{
    return this->favoritado;
}
