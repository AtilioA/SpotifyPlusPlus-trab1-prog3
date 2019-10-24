#include "../include/Musica.hpp"

void Musica::formataDuracao(string duracao)
{
    //this->duracao recebe uma versão formatada da string
}

Musica::Musica()
{
    //
}

Musica::Musica(string nome, int codigo, Midia::Genero *genero, float duracao, int ano) : Midia(nome, codigo, genero, duracao, ano)
{
    this->anoLancamento = ano;
}

void Musica::imprimeInfoProduto()
{
    //
}

void Musica::imprimeNoArquivo(ofstream &outfile)
{
    outfile << this->getNome() << ";" << this->getTipo() << ";";
    list<Produtor*>::iterator it = this->produtor.begin();
    outfile << (*it)->getNome();
    for(it++; it != this->produtor.end(); it++){
        outfile << ", " << (*it)->getNome();
    }
    outfile << ";" << this->getDuracao() << ";" << this->getGenero()->getNome() << ";;";
    if(this->getAlbum() == NULL){
        outfile << ";";
    }else{
        outfile << this->getAlbum()->getCodigo() << ";";
    }
    outfile << this->getAnoLancamento() << "\n";
}

void Musica::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

char Musica::getTipo(){
    return 'M';
}

Album* Musica::getAlbum(){
    return this->album;
}

void Musica::setAlbum(Album* album){
    this->album = album;
}