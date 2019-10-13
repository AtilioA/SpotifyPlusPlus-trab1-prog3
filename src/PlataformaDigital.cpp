#include "../include/PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital()
{
    //
}

PlataformaDigital::PlataformaDigital(string _nome)
{
    this->nome = _nome;
}

void PlataformaDigital::imprimeProdutos(string genero)
{
    //
}

void PlataformaDigital::imprimeAssinantes()
{
    //
}

void PlataformaDigital::inserirAssinante()
{
    //
}

void PlataformaDigital::removerAssinante()
{
    //
}

int PlataformaDigital::inserirProduto(Midia *novoProduto, string nomeProdutor)
{
    //

    return 0;
}

int PlataformaDigital::selecionaAssinante()
{
    //

    return 0;
}

void PlataformaDigital::inserirProdutoAssinante()
{
    //
}

vector<Midia *> PlataformaDigital::getProdutosCadastrados()
{
    return this->produtosCadastrados;
}

vector<Assinante *> PlataformaDigital::getAssinantes()
{
    return this->assinantes;
}

void PlataformaDigital::imprimeNoArquivo(ofstream &outfile)
{
    //
}

void PlataformaDigital::carregaArquivoMidias(ifstream &infile)
{
    int cod;
    string nome;
    char tipo;
    int codProd;
    float minFloat;
    int minDur;
    string primeiroGenero;
    int temporada;
    string album;
    int ano;
    string primeiraLinha;
    Midia *produto;
    vector<int> produtores;
    Album *albumOB;
    vector<Album *> *albunsDeArtista;
    vector<Podcast *> *podcasts;
    // vector<Produtor*> produtores;
    getline(infile, primeiraLinha);  // Ignorando primeira linha
    while (!infile.eof())
    {
        infile >> cod;
        infile.ignore(1, ';');
        getline(infile, nome, ';');
        infile >> tipo;
        infile.ignore(1, ';');
        infile >> codProd;
        produtores.push_back(codProd);

        if (infile.peek() == ',')
        {
            infile.ignore(1, ',');
        }

        while (infile.peek() != ';')
        {
            infile >> codProd;
            produtores.push_back(codProd);
            if (infile.peek() == ',')
            {
                infile.ignore(1, ',');
            }
        }

        infile.ignore(1, ';');
        infile >> minDur;
        infile.ignore(1, ',');
        infile >> minFloat;
        minFloat = minDur + minFloat;
        infile.ignore(1, ';');
        getline(infile, primeiroGenero, ';');
        primeiroGenero.resize(2); // Limita ao primeiro gênero

        // Tratamento de Temporada de acordo com Tipo
        if (tipo == 'P')
        {
            infile >> temporada;
            infile.ignore(1, ';');
        }
        else
        {
            temporada = -1;
            infile.ignore(1, ';');
        }
        getline(infile, album, ';');
        infile >> ano;

        vector<Midia::Genero *>::iterator itGeneros;
        for (itGeneros = this->generosCadastrados.begin(); itGeneros != this->generosCadastrados.end(); itGeneros++)
        {
            if ((*itGeneros)->getSigla() == primeiroGenero)
            {
                break;
            }
        }

        // Criando objeto de acordo com Tipo
        if (tipo == 'P')
        {
            produto = new Podcast(nome, cod, (*itGeneros), temporada);
        }
        else
        {
            produto = new Musica(nome, cod, (*itGeneros), minFloat, ano);
            if (!album.empty())
            {
                albumOB = new Album(album, minFloat, ano, 1);
                albumOB->adicionarMusica((Musica *)produto);
            }
        }
        this->produtosCadastrados.push_back(produto);

        for (vector<int>::iterator itProdutores = produtores.begin(); itProdutores != produtores.end(); itProdutores++)
        {
            for (vector<Produtor *>::iterator itProdutoresCad = this->produtoresCadastrados.begin(); itProdutoresCad != this->produtoresCadastrados.end(); itProdutoresCad++)
            {
                if ((*itProdutores) == (*itProdutoresCad)->getCodigo())
                {
                    if (typeid(*(*itProdutoresCad)) == typeid(Podcaster))
                    {
                        podcasts = ((Podcaster *)(*itProdutoresCad))->getPodcasts();
                        podcasts->push_back((Podcast *)produto);
                    }
                    else
                    {
                        //albunsDeArtista = ((Artista*)(*itProdutoresCad))->getAlbuns();
                    }
                }
            }
        }
        produtores.clear();

        cout << cod << "][" << nome << "][" << tipo << "][" << codProd << "][" << minFloat << "][" << primeiroGenero << "][" << temporada << "][" << album << "][" << ano << '\n';
    }
}

void PlataformaDigital::carregaArquivoGeneros(ifstream &infile)
{
    string sigla;
    string nome;
    string primeiraLinha;
    getline(infile, primeiraLinha);  // Ignorando primeira linha
    while (!infile.eof())
    {
        getline(infile, sigla, ';');
        getline(infile, nome);
        //nome.resize(nome.size() - 1);
        if (infile.eof())
        {
            break;
        }
        this->generosCadastrados.push_back(new Midia::Genero(nome, sigla));
    }
}

void PlataformaDigital::imprimeGeneros()
{
    for (size_t i = 0; i < this->generosCadastrados.size(); i++)
    {
        cout << this->generosCadastrados.at(i)->getSigla() << ";" << this->generosCadastrados.at(i)->getNome() << endl;
    }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile)
{
    while (!infile.eof())
    {
    }
}

void PlataformaDigital::carregaArquivoUsuarios(ifstream &infile)
{
    string primeiraLinha;
    getline(infile, primeiraLinha);  // Ignorando primeira linha
    int cod;
    string nome;
    char tipo;

    while (!infile.eof())
    {
        infile >> cod;
        infile.ignore(1, ';');
        infile >> tipo;
        infile.ignore(1, ';');
        getline(infile, nome);
        //nome.resize(nome.size() - 1);
        if (infile.eof())
        {
            break;
        }
        switch (tipo) // Switch para cadastrar de acordo com tipo de usuário
        {
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

void PlataformaDigital::imprimeUsuarios()
{
    for (size_t i = 0; i < this->assinantes.size(); i++)
    {
        cout << this->assinantes[i]->getCodigo() << ";" << this->assinantes[i]->getNome() << "\n";
    }
}

void PlataformaDigital::imprimeProdutores()
{
    for (size_t i = 0; i < this->assinantes.size(); i++)
    {
        cout << this->produtoresCadastrados[i]->getCodigo() << ";" << this->produtoresCadastrados[i]->getNome() << endl;
    }
}

void PlataformaDigital::exportarBiblioteca()
{
    //
}

void PlataformaDigital::gerarRelatorios()
{
    //
}

string PlataformaDigital::getNome()
{
    return this->nome;
}

void PlataformaDigital::setNome(string nome)
{
    this->nome = nome;
}

void PlataformaDigital::setAssinantes(vector<Assinante *> assinantes)
{
    this->assinantes = assinantes;
}

void PlataformaDigital::setProdutosCadastrados(vector<Midia *> produtosCadastrados)
{
    this->produtosCadastrados = produtosCadastrados;
}
