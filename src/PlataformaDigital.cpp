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
    string linha_1;
    getline(infile, linha_1);
    while(!infile.eof()){
        getline(infile, sigla, ';');
        getline(infile, nome);
        if(infile.eof()){
            break;
        }
        this->generosCadastrados.push_back(new Midia::Genero(nome, sigla));
    }
}

void PlataformaDigital::imprimeGeneros(){
    for(int i = 0; i < this->generosCadastrados.size(); i++){
        cout << this->generosCadastrados.at(i)->getSigla() << ";" << this->generosCadastrados.at(i)->getNome() << endl;
    }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile){
    while(!infile.eof()){
        
    }
}

void PlataformaDigital::carregaArquivoUsuarios(ifstream &infile){
    string linha_1;
    getline(infile, linha_1);
    int cod;
    string nome;
    char tipo;
    while(!infile.eof()){
        infile >> cod;
        infile.ignore(1,';');
        infile >> tipo;
        infile.ignore(1, ';');
        getline(infile, nome);
        nome.pop_back();
        if(infile.eof()){
            break;
        }
        switch(tipo){
            case 'A':
                this->prodrutoresCadastrados.push_back(new Artista(nome, cod));
                break;
            case 'P':
                this->prodrutoresCadastrados.push_back(new Podcaster(nome, cod));
                break;
            case 'U':
                this->assinantes.push_back(new Assinante(nome, cod));
                break;
            default:
                break;
        }
    }
}

void PlataformaDigital::imprimeUsuarios(){
    for(int i = 0; i < this->assinantes.size(); i++){
        cout << this->assinantes[i]->getNome() << ";" << this->assinantes[i]->getCodigo() << endl;
    }
}

void PlataformaDigital::imprimeProdutores(){
    for(int i = 0; i < this->assinantes.size(); i++){
        cout << this->prodrutoresCadastrados[i]->getNome() << ";" << this->prodrutoresCadastrados[i]->getCodigo() << endl;
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
