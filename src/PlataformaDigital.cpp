#include "../include/PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital(){
    //
}

PlataformaDigital::PlataformaDigital(string _nome){
    this->nome = _nome;
}

void PlataformaDigital::imprimeProdutos(string genero){
    //
}

void PlataformaDigital::imprimeAssinantes(){
    //
}

void PlataformaDigital::inserirAssinante(){
    //
}

void PlataformaDigital::removerAssinante(){
    //
}

int PlataformaDigital::inserirProduto(Midia * novoProduto, string nomeProdutor){
    //
}

int PlataformaDigital::selecionaAssinante(){
    //
}

void PlataformaDigital::inserirProdutoAssinante(){
    //
}

vector<Midia*> PlataformaDigital::getProdutosCadastrados(){
    return this->produtosCadastrados;
}

vector<Assinante*> PlataformaDigital::getAssinantes(){
    return this->assinantes;
}

void PlataformaDigital::imprimeNoArquivo(ofstream &outfile){
    //
}

void PlataformaDigital::carregaArquivoMidias(ifstream &infile){
    while(!infile.eof()){

    }
}

void PlataformaDigital::carregaArquivoGeneros(ifstream &infile){
    string sigla;
    string nome;
    while(!infile.eof()){
        getline(infile, sigla, ';');
        getline(infile, nome);
        this->generosCadastrados.push_back(new Midia::Genero(nome, sigla));
    }
}

void PlataformaDigital::imprimeGeneros(){
    for(int i = 0; i < this->generosCadastrados.size(); i++){
        cout << this->generosCadastrados.at(i)->getSigla() << endl;
        cout << this->generosCadastrados.at(i)->getNome() << endl;
    }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile){
    while(!infile.eof()){
        
    }
}

void carregaArquivoAssinantes(ifstream &infile){
    while(!infile.eof()){
        
    }
}


void PlataformaDigital::exportarBiblioteca(){
    //
}

void PlataformaDigital::gerarRelatorios(){
    //
}

string PlataformaDigital::getNome(){
    return this->nome;
}

void PlataformaDigital::setNome(string nome){
    this->nome = nome;
}

void PlataformaDigital::setAssinantes(vector<Assinante*> assinantes){
    this->assinantes = assinantes;
}

void PlataformaDigital::setProdutosCadastrados(vector<Midia*> produtosCadastrados){
    this->produtosCadastrados = produtosCadastrados;
}
