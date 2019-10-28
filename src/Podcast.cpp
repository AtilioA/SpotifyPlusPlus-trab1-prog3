#include "../include/Podcast.hpp"

Podcast::Podcast()
{
}

Podcast::Podcast(string nome, int codigo, Midia::Genero *gen, int qtdTemp, float duracao, int ano) : Midia(nome, codigo, gen, duracao, ano)
{
    this->qtdTemporadas = qtdTemp;
}

void Podcast::imprimeNoArquivo(ofstream &outfile)
{
    outfile << this->getNome() << ";" << this->getTipo() << ";";

    list<Produtor *>::iterator it = this->produtor.begin();
    outfile << (*it)->getNome();
    for (it++; it != this->produtor.end(); it++)
    {
        outfile << ", " << (*it)->getNome();
    }

    outfile << ";" << floatPontoParaVirgula(this->getDuracao()) << ";" << this->getGenero()->getNome() << ";" << this->getTemporada() << ";;" << this->getAnoLancamento() << "\n";
}

int Podcast::getQtdTemporadas()
{
    return this->qtdTemporadas;
}

void Podcast::setQtdTemporadas(int qtdTemporadas)
{
    this->qtdTemporadas = qtdTemporadas;
}

char Podcast::getTipo()
{
    return 'P';
}

int Podcast::getTemporada()
{
    return this->qtdTemporadas;
}
