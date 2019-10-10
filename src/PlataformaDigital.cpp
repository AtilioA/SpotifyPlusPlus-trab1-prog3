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
    int cod;
    string nome;
    char tipo;
    int codProd;
    float minFloat;
    int minDur;
    string genPrim;
    int temporada;
    string album;
    int ano;
    string linha_1;
    // vector<Produtor*> produtores;
    getline(infile, linha_1);
    while(!infile.eof()){
        infile >> cod;
        infile.ignore(1, ';');
        getline(infile, nome, ';');
        infile >> tipo;
        infile.ignore(1, ';');
        vector<int> produtores;
        infile >> codProd;
        produtores.push_back(codProd);
        if(infile.peek() == ','){
            infile.ignore(1, ',');
        }
        while(infile.peek() != ';'){
            infile >> codProd;
            produtores.push_back(codProd);
            if(infile.peek() == ','){
                infile.ignore(1, ',');
            }
        }
        infile.ignore(1, ';');
        infile >> minDur;
        infile.ignore(1, ',');
        infile >> minFloat;
        minFloat = minDur + minFloat;
        infile.ignore(1, ';');
        getline(infile, genPrim, ';');
        genPrim.resize(2);
        if(tipo == 'P'){
            infile >> temporada;
            infile.ignore(1,';');
        }else{
            temporada = -1;
            infile.ignore(1,';');
        }
        getline(infile, album, ';');
        infile >> ano;
        cout << cod << "][" << nome << "][" << tipo  << "]["  << codProd << "][" << minFloat << "][" << genPrim << "][" << temporada << "][" << album << "][" << ano << '\n';
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
        if(infile.eof()){
            break;
        }
        switch(tipo){
            case 'A':
                this->produtoresCadastrados.push_back(new Artista(nome, cod));
                break;
            case 'P':
                this->produtoresCadastrados.push_back(new Podcaster(nome, cod));
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
        cout << this->assinantes[i]->getCodigo() << ";" << this->assinantes[i]->getNome() << "\n";
    }
}

void PlataformaDigital::imprimeProdutores(){
    for(int i = 0; i < this->assinantes.size(); i++){
        cout << this->produtoresCadastrados[i]->getCodigo() << ";" << this->produtoresCadastrados[i]->getNome() << endl;
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
