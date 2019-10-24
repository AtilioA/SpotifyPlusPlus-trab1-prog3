#include "../include/PlataformaDigital.hpp"

void retiraCR(string &ent)
{
    if (ent.at(ent.size() - 1) == '\r')
    {
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

list<Midia *> PlataformaDigital::getProdutosCadastrados()
{
    return this->produtosCadastrados;
}

list<Assinante *> PlataformaDigital::getAssinantes()
{
    return this->assinantes;
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

void PlataformaDigital::imprimeProdutos(string genero)
{
    //
}

void PlataformaDigital::imprimeAssinantes()
{
    //
}

void PlataformaDigital::insereAssinante()
{
    //
}

void PlataformaDigital::removeAssinante()
{
    //
}

int PlataformaDigital::insereProduto(Midia *novoProduto, string nomeProdutor)
{
    //

    return 0;
}

int PlataformaDigital::selecionaAssinante()
{
    //

    return 0;
}

void PlataformaDigital::insereProdutoAssinante()
{
    //
}

void PlataformaDigital::imprimeNoArquivo(ofstream &outfile)
{
    //
}

void PlataformaDigital::carregaArquivoMidias(ifstream &infile)
{
    string linhaAtual;
    int cod;
    string nome;
    char tipo;
    int codProd;
    float floatDur;
    //int intDur;
    string strDur;
    string primeiroGenero;
    int temporada;
    string album;
    int codAlbum;
    int anoPublicacao;
    string primeiraLinha;
    Midia *produto;
    list<int> produtores;
    Album *albumNovo;
    int qtdGeneros = 0;

    getline(infile, primeiraLinha); // Ignorando primeira linha

    while (!infile.eof())
    {
        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);
        // if (linhaAtual.empty())
        // {
        //     break;
        // }
        // if (!(linhaAtualStream >> cod))
        // {
        //     cerr << "Erro de formatação (código de mídia não é número)\n";
        //     exit(2);
        // }
        try{
            if (!(linhaAtualStream >> cod))
            {
                throw "Erro de formatação (código de mídia não é número)\n";
            }
        }catch (const char* msg){
            cerr << msg << "\n";
            exit(2);
        }
        //cout << cod << "\n";
        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, nome, ';');
        linhaAtualStream >> tipo;
        linhaAtualStream.ignore(1, ';');
        try{
            if (!(linhaAtualStream >> codProd))
            {
                throw "Erro de formatação (código de produtor não é número)\n";
            }
        }catch (const char* msg){
            cerr << msg << "\n";
            exit(2);
        }
        produtores.push_back(codProd);

        if (linhaAtualStream.peek() == ',')
        {
            linhaAtualStream.ignore(1, ',');
        }

        while (linhaAtualStream.peek() != ';')
        {
            try{
                if (!(linhaAtualStream >> codProd))
                {
                    throw "Erro de formatação (código de produtor não é número)\n";
                }
            }catch (const char* msg){
                cerr << msg << "\n";
                exit(2);
            }
            produtores.push_back(codProd);
            if (linhaAtualStream.peek() == -1)
            {
                break;
            }
            if (linhaAtualStream.peek() == ',')
            {
                linhaAtualStream.ignore(1, ',');
            }
        }

        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, strDur, ';');
        for (char &itChar : strDur)
        {
            if (itChar == ',')
            {
                itChar = '.';
            }
        }
        stringstream streamDur(strDur);
        // streamDur >> floatDur;
        // if (!(streamDur >> floatDur))
        // {
        //     cerr << "Erro de formatação (duração não é número)\n";
        //     exit(2);
        // }
        try{
            if (!(streamDur >> floatDur))
            {
                throw "Erro de formatação (duração não é número)\n";
            }
        }catch (const char* msg){
            cerr << msg << "\n";
            exit(2);
        }
        getline(linhaAtualStream, primeiroGenero, ';');
        //cout << primeiroGenero << endl;

        for (char itGenero : primeiroGenero)
        {
            if (itGenero == ',')
            {
                primeiroGenero.resize(qtdGeneros); // Limita ao primeiro gênero
                break;
            }
            qtdGeneros++;
        }
        qtdGeneros = 0;
        //cout << nome << endl;
        // Tratamento de Temporada de acordo com Tipo
        if (tipo == 'P')
        {
            // if (!(linhaAtualStream >> temporada))
            // {
            //     cerr << "Erro de formatação (código de temporada não é número)\n";
            //     exit(2);
            // }
            try{
                if (!(linhaAtualStream >> temporada))
                {
                    throw "Erro de formatação (código de temporada não é número)\n";
                }
            }catch (const char* msg){
                cerr << msg << "\n";
                exit(2);
            }
            linhaAtualStream.ignore(1, ';');
        }
        else
        {
            temporada = -1;
            linhaAtualStream.ignore(1, ';');
        }

        getline(linhaAtualStream, album, ';');
        if (!album.empty() && !(linhaAtualStream >> codAlbum) && tipo == 'M')
        {
            cerr << "Erro de formatação (código de álbum não é número)\n";
            exit(2);
        }
        linhaAtualStream.ignore(1, ';');
        if (!(linhaAtualStream >> anoPublicacao) && tipo == 'M')
        {
            cerr << "Erro de formatação (ano de publicação não é número)\n";
            exit(2);
        }

        int achouGenero = 0;
        Midia::Genero *generoDaMidia;
        for (Midia::Genero *itGenero : this->generosCadastrados)
        { // O método compare retorna 0 quando as strings são iguais
            if (itGenero->getSigla().compare(primeiroGenero) == 0)
            {
                achouGenero = 1;
                generoDaMidia = itGenero;
                break;
            }
        }

        if (achouGenero == 0)
        {
            /* Inconsistência nos dados de entrada:
             * por exemplo, uso de Código de gênero ou usuário inexistente nos respectivos cadastros, etc
             */
            cerr << "Inconsistências na entrada (não achou gênero)\n";
            exit(3);
        }

        // Criando objeto de acordo com Tipo
        if (tipo == 'P')
        {
            produto = new Podcast(nome, cod, generoDaMidia, temporada, floatDur);
        }
        else if (tipo == 'M')
        {
            produto = new Musica(nome, cod, generoDaMidia, floatDur, anoPublicacao);
        }
        else
        {
            cerr << "Inconsistências na entrada (tipo inválido de mídia)\n";
            exit(3);
        }

        generoDaMidia->adicionaMidia(produto);
        this->produtosCadastrados.push_back(produto);

        Album *albumDaMusica = NULL;
        for (Album *itAlbuns : this->albunsCadastrados)
        {
            if (itAlbuns->getCodigo() == codAlbum)
            {
                albumNovo = itAlbuns;
                albumDaMusica = itAlbuns;
                break;
            }
        }
        if (albumDaMusica == NULL && !album.empty())
        {
            albumNovo = new Album(album, codAlbum, floatDur, anoPublicacao, 1);
            this->albunsCadastrados.push_back(albumNovo);
        }

        size_t produtoresEncontrados = 0;
        for (int itProdutores : produtores)
        {
            for (Produtor *itProdutoresCad : this->produtoresCadastrados)
            {
                if (itProdutores == itProdutoresCad->getCodigo())
                {
                    produtoresEncontrados++;
                    produto->adicionaProdutor(itProdutoresCad);
                    itProdutoresCad->novoProduto(produto);

                    if (tipo == 'P')
                    {
                        ((Podcaster *)itProdutoresCad)->inserePodcast((Podcast *)produto);
                    }
                    else
                    {
                        if (!album.empty())
                        {
                            albumNovo->adicionaMusica((Musica *)produto);
                            if (((Artista *)itProdutoresCad)->procuraAlbum(album) == NULL)
                            {
                                ((Artista *)itProdutoresCad)->insereAlbum(albumNovo);
                            }
                        }
                    }
                }
            }
        }

        if (produtoresEncontrados != produtores.size())
        {
            cerr << "Inconsistências na entrada (não achou todos os produtores)\n";
            exit(3);
        }

        produtores.clear();

        if (infile.peek() == -1)
        {
            break;
        }
    }
}

void PlataformaDigital::carregaArquivoGeneros(ifstream &infile)
{
    string sigla;
    string nome;
    string primeiraLinha;
    string linhaAtual;
    getline(infile, primeiraLinha); // Ignorando primeira linha
    while (!infile.eof())
    {
        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);
        getline(linhaAtualStream, sigla, ';');
        getline(linhaAtualStream, nome);
        //nome.resize(nome.size() - 1);
        this->generosCadastrados.push_back(new Midia::Genero(nome, sigla));
        if (infile.peek() == -1)
        {
            break;
        }
    }
}

void PlataformaDigital::imprimeGeneros()
{
    for (Midia::Genero *it : this->generosCadastrados)
    {
        cout << it->getSigla() << ';' << it->getNome() << "\n";
    }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile)
{
    string primeiraLinha;
    int cod = 0;
    int favoritoAtual = 0;
    list<int> favoritos;
    getline(infile, primeiraLinha); // Ignorando primeira linha
    string linhaAtual;
    while (!infile.eof())
    {
        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);
        if (linhaAtual.empty())
        {
            break;
        }
        if (!(linhaAtualStream >> cod))
        {
            cerr << "Erro de formatação (código de favorito não é número)\n";
            exit(2);
        }
        linhaAtualStream.ignore(1, ';');
        if (linhaAtualStream.peek() == -1)
        {
            continue;
        }

        if (!(linhaAtualStream >> favoritoAtual))
        {
            cerr << "Erro de formatação (código de mídia não é número)\n";
            exit(2);
        }
        favoritos.push_back(favoritoAtual);
        while (linhaAtualStream.peek() == ',')
        {
            linhaAtualStream.ignore(1, ',');
            if (!(linhaAtualStream >> favoritoAtual))
            {
                cerr << "Erro de formatação (código de mídia não é número)\n";
                exit(2);
            }
            favoritos.push_back(favoritoAtual);
        }

        Assinante *assinanteAtual = NULL;
        for (Assinante *itAssinante : this->assinantes)
        {
            if (itAssinante->getCodigo() == cod)
            {
                assinanteAtual = itAssinante;
                break;
            }
        }

        if (assinanteAtual == NULL)
        { // dps vamo tentar fazer com try catch
            cerr << "Inconsistências na entrada (código não pertence a nenhum assinante)\n";
            exit(3);
        }

        int achouFavorito = 0;
        for (int itFavs : favoritos)
        {
            for (Midia *itFavsM : this->produtosCadastrados)
            {
                if (itFavs == itFavsM->getCodigo())
                {
                    assinanteAtual->insereFavoritos(itFavsM);
                    achouFavorito = 1;
                }
            }
        }
        if (achouFavorito == 0)
        {
            cerr << "Inconsistências na entrada (código de mídia de favorito não pertence a nenhuma mídia)\n";
            exit(3);
        }

        favoritos.clear();
    }
}

void PlataformaDigital::carregaArquivoUsuarios(ifstream &infile)
{
    string primeiraLinha;
    getline(infile, primeiraLinha); // Ignorando primeira linha
    int cod;
    string nome;
    char tipo;
    string linhaAtual;

    while (!infile.eof())
    {
        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);
        if (linhaAtual.empty())
        {
            break;
        }
        if (!(linhaAtualStream >> cod))
        {
            cerr << "Erro de formatação (código de usuário não é número)\n";
            exit(2);
        }
        // Verificar se é número (Erro 2)
        linhaAtualStream.ignore(1, ';');
        linhaAtualStream >> tipo;
        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, nome);
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
            cerr << "Erro de formatação (Tipo de usuário não é A, P nem U)\n";
            exit(2);
            break;
        }
    }

    this->assinantes.sort(ordenaPorNome<Assinante>);
    this->produtoresCadastrados.sort(ordenaPorNome<Produtor>);
}

void PlataformaDigital::imprimeUsuarios()
{
    for (Assinante *it : this->assinantes)
    {
        cout << it->getCodigo() << ";" << it->getNome() << "\n";
    }
}

void PlataformaDigital::imprimeProdutores()
{
    for (Produtor *it : this->produtoresCadastrados)
    {
        cout << it->getCodigo() << ";" << it->getNome() << "\n";
    }
}

void PlataformaDigital::exportaBiblioteca()
{
    //
}

void PlataformaDigital::geraRelatorioEstatisticas()
{
    ofstream estatistica;

    estatistica.open("1-estatisticas.txt");
    estatistica << "Horas Consumidas: " << this->tempoConsumido() << endl;
}

void PlataformaDigital::geraRelatorioMidiasProdutores()
{
    ofstream midias_prods;

    midias_prods.open("2-produtores.csv");
    if (midias_prods.is_open())
    {
        for (Produtor *it : this->produtoresCadastrados)
        {
            it->imprimeNoArquivo(midias_prods);
        }
    }

    midias_prods.close();
}

void PlataformaDigital::geraRelatorioFavoritos()
{
    ofstream favoritos;
}

void PlataformaDigital::geraRelatorioBackup()
{
    ofstream backup;

    backup.open("4-backup.txt");
    if (backup.is_open())
    {
        for (Produtor *it : this->produtoresCadastrados)
        {
            it->imprimeNoArquivo(backup);
        }
    }

    backup.close();
}

void PlataformaDigital::geraRelatorios()
{
}

float PlataformaDigital::tempoConsumido()
{
    float tempoTotal = 0;

    for (Assinante *itUsuario : this->assinantes)
    {
        tempoTotal += itUsuario->calculaTempoFavs();
    }

    return tempoTotal;
}

PlataformaDigital::~PlataformaDigital(){
    for(Assinante* itAss: this->assinantes){
        delete itAss;
    }
    for(Midia* itMidia : this->produtosCadastrados){
        delete itMidia;
    }
    for(Midia::Genero* itGen: this->generosCadastrados){
        delete itGen;
    }
    for(Produtor* itProd: this->produtoresCadastrados){
        delete (Podcaster*) itProd;
    }
    for(Album* itAlbum: this->albunsCadastrados){
        delete itAlbum;
    }
}
