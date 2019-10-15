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

list<Midia *> PlataformaDigital::getProdutosCadastrados()
{
    return this->produtosCadastrados;
}

list<Assinante *> PlataformaDigital::getAssinantes()
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
    float floatDur;
    int intDur;
    string primeiroGenero;
    int temporada;
    string album;
    int ano;
    string primeiraLinha;
    Midia *produto;
    list<int> produtores;
    // list<Produtor*> produtores;
    Album *albumNovo;
    //list<Podcast *> *podcasts;
    // list<Album *> *albunsDeArtista;
    int generoContador = 0;
    getline(infile, primeiraLinha);  // Ignorando primeira linha
    while (!infile.eof())
    {
        infile >> cod;  // Verificar se é número (Erro 2)
        infile.ignore(1, ';');
        getline(infile, nome, ';');
        retiraCR(nome);
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
        infile >> intDur;
        infile.ignore(1, ',');
        infile >> floatDur;
        floatDur = intDur + (floatDur/100);
        infile.ignore(1, ';');
        getline(infile, primeiroGenero, ';');
        for(string::iterator itGenero = primeiroGenero.begin(); itGenero != primeiroGenero.end(); itGenero++){
            if((*itGenero) == ','){
                primeiroGenero.resize(generoContador); // Limita ao primeiro gênero
                break;
            }
            generoContador++;
        }
        generoContador = 0;
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
        list<Midia::Genero *>::iterator itGeneros;
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
            cerr << "Inconsistências na entrada (não achou gênero)" << endl;
            exit(3);
        }

        // Criando objeto de acordo com Tipo
        if (tipo == 'P')
        {
            produto = new Podcast(nome, cod, (*itGeneros), temporada);
        }
        else
        {
            produto = new Musica(nome, cod, (*itGeneros), floatDur, ano);
        }

        this->produtosCadastrados.push_back(produto);
        size_t achastesProd = 0;

        for (list<int>::iterator itProdutores = produtores.begin(); itProdutores != produtores.end(); itProdutores++)
        {
            for (list<Produtor *>::iterator itProdutoresCad = this->produtoresCadastrados.begin(); itProdutoresCad != this->produtoresCadastrados.end(); itProdutoresCad++)
            {
                if ((*itProdutores) == (*itProdutoresCad)->getCodigo())
                {
                    achastesProd++;
                    produto->adicionarProdutor((*itProdutoresCad));
                    (*itProdutoresCad)->novoProduto(produto);

                    if (tipo == 'P')
                    {
                        ((Podcaster *)(*itProdutoresCad))->inserirPodcast((Podcast *)produto);
                    }
                    else
                    {
                        //cout << produto->getNome() << ";" << produto->getCodigo() << '\n';
                        //((Artista*)(*itProdutoresCad))->inserirMusica((Musica*) produto);
                        if (!album.empty())
                        {
                            if(((Artista *)(*itProdutoresCad))->procurarAlbum(album) != NULL){
                                albumNovo = ((Artista *)(*itProdutoresCad))->procurarAlbum(album);
                                albumNovo->adicionarMusica((Musica*) produto);
                            }else{
                                albumNovo = new Album(album, floatDur, ano, 1);
                                albumNovo->adicionarMusica((Musica*) produto);
                                ((Artista *)(*itProdutoresCad))->inserirAlbum(albumNovo);
                            }
                        }
                        //albunsDeArtista = ((Artista*)(*itProdutoresCad))->getAlbuns();
                    }
                }
            }
        }

        if (achastesProd != produtores.size()) // não sei se tá certo, é só uma ideia
        {
            cerr << "Inconsistências na entrada (não achou todos os produtores" << endl;
            exit(3);
        }
        produtores.clear();

        //cout << '[' << cod << "][" << nome << "][" << tipo << "][" << codProd << "][" << floatDur << "][" << primeiroGenero << "][" << temporada << "][" << album << "][" << ano << "]\n";
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
    for(list<Midia::Genero*>::iterator it = this->generosCadastrados.begin(); it != this->generosCadastrados.end(); it++){
        cout << (*it)->getSigla() << ";" << (*it)->getNome() << endl;
    }
    // for (size_t i = 0; i < this->generosCadastrados.size(); i++)
    // {
    //     cout << this->generosCadastrados.at(i)->getSigla() << ";" << this->generosCadastrados.at(i)->getNome() << endl;
    // }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile)
{
    char teste;
    string primeiraLinha;
    int cod = 0;
    int favoritoAtual = 0;
    list<int> favoritos;
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
            list<Assinante*>::iterator itAssinante;

            for (itAssinante = this->assinantes.begin(); itAssinante != this->assinantes.end(); itAssinante++){
                if ((*itAssinante)->getCodigo() == cod)
                {
                    break;
                }
            }

            list<Midia*>::iterator itMidias;
            for (list<int>::iterator itFavoritos = favoritos.begin(); itFavoritos != favoritos.end(); itFavoritos++)
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
    this->assinantes.sort(ordenarPorNome<Assinante>);
    this->produtoresCadastrados.sort(ordenarPorNome<Produtor>);
}

void PlataformaDigital::imprimeUsuarios()
{

    for(list<Assinante*>::iterator it = this->assinantes.begin(); it != this->assinantes.end(); it++){
        cout << (*it)->getCodigo() << ";" << (*it)->getNome() << "\n";
    }

    // for (size_t i = 0; i < this->assinantes.size(); i++)
    // {
    //     cout << this->assinantes[i]->getCodigo() << ";" << this->assinantes[i]->getNome() << "\n";
    //     /*
    //     for (size_t size_favoritos = 0; size_favoritos < this->assinantes[i]->getFavoritos().size(); size_favoritos++)
    //     {
    //         cout << (this->assinantes[i]->getFavoritos())[size_favoritos]->getCodigo() << '\n';
    //     }
    //     */
    // }
}

void PlataformaDigital::imprimeProdutores()
{
    for(list<Produtor*>::iterator it = this->produtoresCadastrados.begin(); it != this->produtoresCadastrados.end(); it++){
        cout << (*it)->getCodigo() << ";" << (*it)->getNome() << "\n";
    }
    // for (size_t i = 0; i < this->assinantes.size(); i++)
    // {
    //     cout << this->produtoresCadastrados[i]->getCodigo() << ";" << this->produtoresCadastrados[i]->getNome() << endl;
    // }
}

void PlataformaDigital::exportarBiblioteca()
{
    //
}

void PlataformaDigital::gerarRelatorios()
{
    ofstream midias_prods;
    midias_prods.open("2-produtores.csv");
    if(midias_prods.is_open()){
        for(list<Produtor*>::iterator it = this->produtoresCadastrados.begin(); it != this->produtoresCadastrados.end(); it++){
            (*it)->imprimeNoArquivo(midias_prods);
            //cout << "quero saber pq n chama\n";
        }
    }
    midias_prods.close();
}

string PlataformaDigital::getNome()
{
    return this->nome;
}

void PlataformaDigital::setNome(string nome)
{
    this->nome = nome;
}

void PlataformaDigital::setAssinantes(list<Assinante *> assinantes)
{
    this->assinantes = assinantes;
}

void PlataformaDigital::setProdutosCadastrados(list<Midia *> produtosCadastrados)
{
    this->produtosCadastrados = produtosCadastrados;
}
