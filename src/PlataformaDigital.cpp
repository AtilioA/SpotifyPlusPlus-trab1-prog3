#include "../include/PlataformaDigital.hpp"

void retiraCR(string &ent)
{
    if(ent.at(ent.size() - 1) == '\r'){
        ent.resize(ent.size() - 1);
    }
}

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
    // vector<Produtor*> produtores;
    Album *albumOB;
    vector<Podcast *> *podcasts;
    // vector<Album *> *albunsDeArtista;
    getline(infile, primeiraLinha);  // Ignorando primeira linha
    while (!infile.eof())
    {
        infile >> cod;  // Verificar se é número (Erro 2)
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

        int achaste = 0;
        vector<Midia::Genero *>::iterator itGeneros;
        for (itGeneros = this->generosCadastrados.begin(); itGeneros != this->generosCadastrados.end(); itGeneros++)
        {
            if ((*itGeneros)->getSigla() == primeiroGenero)
            {
                achaste = 1;
                break;
            }
        }
        if (achaste == 0)
        {
            /* Inconsistência nos dados de entrada:
             * por exemplo, uso de Código de gênero ou usuário inexistente nos respectivos cadastros, etc
             */
            cerr << "Inconsistências na entrada" << endl;
            exit(3);
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

        size_t achastesProd = 0;
        for (vector<int>::iterator itProdutores = produtores.begin(); itProdutores != produtores.end(); itProdutores++)
        {
            for (vector<Produtor *>::iterator itProdutoresCad = this->produtoresCadastrados.begin(); itProdutoresCad != this->produtoresCadastrados.end(); itProdutoresCad++)
            {
                if ((*itProdutores) == (*itProdutoresCad)->getCodigo())
                {
                    achastesProd++;
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
        if (achastesProd != produtores.size()) // não sei se tá certo, é só uma ideia
        {
            cerr << "Inconsistências na entrada" << endl;
            exit(3);
        }
        produtores.clear();

        cout << '[' << cod << "][" << nome << "][" << tipo << "][" << codProd << "][" << minFloat << "][" << primeiroGenero << "][" << temporada << "][" << album << "][" << ano << "]\n";
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
    char teste;
    string primeiraLinha;
    int cod = 0;
    int favoritoAtual = 0;
    vector<int> favoritos;
    getline(infile, primeiraLinha);  // Ignorando primeira linha

    while (!infile.eof())
    {
        infile >> cod;  // Verificar se é número (Erro 2)
        infile.ignore(1, ';');
        cout << cod << " a vamo nessa\n";

        if (infile.eof())
        {
            cout << "eof\n";
            break;
        }

        int c = infile.peek();
        if (c == EOF)  // Caso não haja favoritos
        {
            if (infile.eof())
            {
                cout << "supostamente acabou\n";
            }
            else
            {
                cout << "disney\n";
            }
            // infile >> teste;
            // infile.ignore(3, '\r');
            // getline(infile, primeiraLinha);
            cout << "peek = -1\n";
            continue;
        }
        else
        {
            infile >> favoritoAtual;
            favoritos.push_back(favoritoAtual);
            // cout << "tHiago\n";
            while (infile.peek() == ',')
            {
                infile.ignore(1, ',');
                infile >> favoritoAtual;
                favoritos.push_back(favoritoAtual);
                // cout << "icaro\n";
            }

            /*
            vector<Assinante*>::iterator itAssinante;

            for (itAssinante = this->assinantes.begin(); itAssinante != this->assinantes.end(); itAssinante++){
                if ((*itAssinante)->getCodigo() == cod)
                {
                    break;
                }
            }

            vector<Midia*>::iterator itMidias;
            for (vector<int>::iterator itFavoritos = favoritos.begin(); itFavoritos != favoritos.end(); itFavoritos++)
            {
                for (itMidias = this->produtosCadastrados.begin(); itMidias != this->produtosCadastrados.end(); itMidias++)
                {
                    if ((*itFavoritos) == (*itMidias)->getCodigo())
                    {
                        (*itAssinante)->insereFavoritos((*itMidias));
                        break;
                    }
                }
            }

            */
            favoritos.clear();
        }
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
        infile >> cod;  // Verificar se é número (Erro 2)
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
            cerr << "Erro de formatação" << endl;
            exit(2);
            break;
        }
    }
}

void PlataformaDigital::imprimeUsuarios()
{
    for (size_t i = 0; i < this->assinantes.size(); i++)
    {
        cout << this->assinantes[i]->getCodigo() << ";" << this->assinantes[i]->getNome() << "\n";
        /*
        for (size_t size_favoritos = 0; size_favoritos < this->assinantes[i]->getFavoritos().size(); size_favoritos++)
        {
            cout << (this->assinantes[i]->getFavoritos())[size_favoritos]->getCodigo() << '\n';
        }
        */
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
