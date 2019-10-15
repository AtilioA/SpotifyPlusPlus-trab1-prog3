#include "../include/Artista.hpp"

Artista::Artista(string _nome, int codigo) : Produtor(_nome, codigo) {}

void Artista::imprimeNoArquivo(ofstream &outfile)
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

void Artista::carregaArquivo(ifstream &infile)
{
    //
}

void Artista::setAlbuns(list<Album *> albuns)
{
    this->albuns = albuns;
}

list<Album *> *Artista::getAlbuns()
{
    return &(this->albuns);
}

Album* Artista::procurarAlbum(string album){
    for(list<Album*>::iterator it = this->albuns.begin(); it != this->albuns.end(); it++){
        if((*it)->getNome() == album){
            return (*it);
        }
    }
    return NULL;
}

void Artista::inserirAlbum(Album* album){
    this->albuns.push_back(album);
}

void Artista::inserirMusica(Musica* musica){
    this->produtosDesenvolvidos.push_back(musica);
}