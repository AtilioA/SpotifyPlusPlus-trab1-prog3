#include "../include/PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital()
{
    //
}

PlataformaDigital::~PlataformaDigital()
{
    for (Assinante *itAss : this->assinantes)
    {
        delete itAss;
    }
    for (Midia *itMidia : this->produtosCadastrados)
    {
        delete itMidia;
    }
    for (Midia::Genero *itGen : this->generosCadastrados)
    {
        delete itGen;
    }
    for (Produtor *itProd : this->produtoresCadastrados)
    {
        delete (Podcaster *)itProd;
    }
    for (Album *itAlbum : this->albunsCadastrados)
    {
        delete itAlbum;
    }
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
void PlataformaDigital::imprimeGeneros()
{
    for (Midia::Genero *it : this->generosCadastrados)
    {
        cout << it->getSigla() << ';' << it->getNome() << "\n";
    }
}

/* Carregamento de arquivos para a plataforma */
// Lê arquivo midias.csv
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
    Album *albumNovo = NULL;
    int qtdGeneros = 0;

    getline(infile, primeiraLinha); // Ignorando primeira linha

    while (!infile.eof())
    {
        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);

        try
        {
            if (!(linhaAtualStream >> cod))
            {
                throw "Erro de formatação (código de mídia não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }

        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, nome, ';');
        linhaAtualStream >> tipo;
        linhaAtualStream.ignore(1, ';');

        try
        {
            if (!(linhaAtualStream >> codProd))
            {
                throw "Erro de formatação (código de produtor não é número)";
            }
        }
        catch (const char *msg)
        {
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
            try
            {
                if (!(linhaAtualStream >> codProd))
                {
                    throw "Erro de formatação (código de produtor não é número)";
                }
            }
            catch (const char *msg)
            {
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

        try
        {
            if (!(streamDur >> floatDur))
            {
                throw "Erro de formatação (duração não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }

        getline(linhaAtualStream, primeiroGenero, ';');

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

        // Tratamento de Temporada de acordo com Tipo
        if (tipo == 'P')
        {
            try
            {
                if (!(linhaAtualStream >> temporada))
                {
                    throw "Erro de formatação (código de temporada não é número)";
                }
            }
            catch (const char *msg)
            {
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
        try
        {
            if (!album.empty() && !(linhaAtualStream >> codAlbum) && tipo == 'M')
            {
                throw "Erro de formatação (código de álbum não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }

        linhaAtualStream.ignore(1, ';');

        try
        {
            if (!(linhaAtualStream >> anoPublicacao) && tipo == 'M')
            {
                throw "Erro de formatação (ano de publicação não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }

        int achouGenero = 0;
        Midia::Genero *generoDaMidia;
        for (Midia::Genero *itGenero : this->generosCadastrados)
        {
            if (itGenero->getSigla().compare(primeiroGenero) == 0)
            {
                achouGenero = 1;
                generoDaMidia = itGenero;
                break;
            }
        }

        try
        {
            if (achouGenero == 0)
            {
                throw "Inconsistências na entrada (não achou gênero)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(3);
        }

        // Criando objeto de acordo com Tipo
        try
        {
            if (tipo == 'P')
            {
                produto = new Podcast(nome, cod, generoDaMidia, temporada, floatDur, anoPublicacao);
            }
            else if (tipo == 'M')
            {
                produto = new Musica(nome, cod, generoDaMidia, floatDur, anoPublicacao);
            }
            else
            {
                throw "Inconsistências na entrada (tipo inválido de mídia)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
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
                            ((Musica *)produto)->setAlbum(albumNovo);
                            if (((Artista *)itProdutoresCad)->procuraAlbum(album) == NULL)
                            {
                                ((Artista *)itProdutoresCad)->insereAlbum(albumNovo);
                            }
                        }
                        else
                        {
                            ((Musica *)produto)->setAlbum(NULL);
                        }
                    }
                }
            }
        }

        try
        {
            if (produtoresEncontrados != produtores.size())
            {
                throw "Inconsistências na entrada (não achou todos os produtores)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(3);
        }

        produtores.clear();

        if (infile.peek() == -1)
        {
            break;
        }
    }
}

// Lê arquivo generos.csv
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
        this->generosCadastrados.push_back(new Midia::Genero(nome, sigla));
        if (infile.peek() == -1)
        {
            break;
        }
    }
}

// Lê arquivo favoritos.csv
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
        try
        {
            if (!(linhaAtualStream >> cod))
            {
                throw "Erro de formatação (código de mídia não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }
        linhaAtualStream.ignore(1, ';');
        if (linhaAtualStream.peek() == -1)
        {
            continue;
        }

        try
        {
            if (!(linhaAtualStream >> favoritoAtual))
            {
                throw "Erro de formatação (código de mídia não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }

        bool favoritoRepetido = false;
        favoritos.push_back(favoritoAtual);

        while (linhaAtualStream.peek() == ',')
        {
            linhaAtualStream.ignore(1, ',');

            try
            {
                if (!(linhaAtualStream >> favoritoAtual))
                {
                    throw "Erro de formatação (código de mídia fodase não é número)";
                }
            }
            catch (const char *msg)
            {
                cerr << msg << "\n";
                exit(2);
            }

            for (int favorito : favoritos)
            {
                if (favoritoAtual == favorito)
                {
                    favoritoRepetido = true;
                    break;
                }
            }
            if (!favoritoRepetido)
            {
                favoritos.push_back(favoritoAtual);
            }
            favoritoRepetido = false;
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

        try
        {
            if (assinanteAtual == NULL)
            {
                throw "Inconsistências na entrada (código não pertence a nenhum assinante)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(3);
        }

        int achouFavorito = 0;
        for (int itFavs : favoritos)
        {
            for (Midia *itFavsM : this->produtosCadastrados)
            {
                if (itFavs == itFavsM->getCodigo())
                {
                    itFavsM->getGenero()->favoritadoPorUser(itFavsM->getDuracao());
                    assinanteAtual->insereFavoritos(itFavsM);
                    achouFavorito = 1;
                }
            }
        }

        try
        {
            if (achouFavorito == 0)
            {
                throw "Inconsistências na entrada (código de mídia de favorito não pertence a nenhuma mídia";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(3);
        }

        favoritos.clear();
    }
}

// Lê arquivo usuarios.csv
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
        try
        {
            if (!(linhaAtualStream >> cod))
            {
                throw "Erro de formatação (código de usuário não é número)";
            }
        }
        catch (const char *msg)
        {
            cerr << msg << "\n";
            exit(2);
        }

        // Verificar se é número (Erro 2)
        linhaAtualStream.ignore(1, ';');
        linhaAtualStream >> tipo;
        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, nome);

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

/* Escrita de arquivos (relatórios) */
void PlataformaDigital::exportaBiblioteca()
{
    //
}

// Escreve arquivo 1-estatisticas.txt
void PlataformaDigital::geraRelatorioEstatisticas()
{
    ofstream estatistica;

    estatistica.open("1-estatisticas.txt");
    estatistica << "Horas Consumidas: " << this->tempoConsumido() << " minutos\n\n";
    pair<float, Midia::Genero *> par = this->generoMaisEscutado();
    estatistica << "Gênero mais ouvido: " << par.second->getNome() << " - " << par.first << " minutos\n\n";
    estatistica << "Mídias por Gênero:\n";
    this->generosCadastrados.sort(ordenaDecrescPorFavoritado<Midia::Genero>);
    for (Midia::Genero *it : this->generosCadastrados)
    {
        estatistica << it->getNome() << ":" << it->getFavoritado() << "\n";
    }
    this->produtosCadastrados.sort(ordenaDecrescPorFavoritado<Midia>);

    int nMidias = 0;
    estatistica << "\nTop 10 Mídias:\n";
    for (Midia *it : this->produtosCadastrados)
    {
        if (nMidias < 10)
        {
            estatistica << it->getNome() << ":" << it->getGenero()->getNome() << ":" << it->getFavoritado() << "\n";
            nMidias++;
        }
        else
        {
            break;
        }
    }

    int nProdutores = 0;
    estatistica << "\nTop 10 Produtores:\n";
    this->produtoresCadastrados.sort(ordenaDecrescPorFavoritado<Produtor>);
    for (Produtor *it : this->produtoresCadastrados)
    {
        if (nProdutores < 10)
        {
            estatistica << it->getNome() << ":" << it->getFavoritado() << "\n";
            nProdutores++;
        }
        else
        {
            break;
        }
    }
}

// Escreve arquivo 2-produtores.csv
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

// Escreve arquivo 3-favoritos.csv
void PlataformaDigital::geraRelatorioFavoritos()
{
    ofstream favoritos;

    favoritos.open("3-favoritos.csv");

    favoritos << "Código Assinante;Tipo Mídia;Código Mídia;Gênero;Duração\n";

    assinantes.sort(ordenaCrescPorCodigo<Assinante>);
    for (Assinante *assinante : this->assinantes)
    {
        list<Midia *> favs = assinante->getFavoritos();
        favs.sort(ordenaCrescPorCodigo<Midia>);

        for (Midia *midia : favs)
        {
            if (midia->getTipo() == 'P')
            {
                favoritos << assinante->getCodigo() << ";";
                favoritos << "Podcast;" << midia->getCodigo() << ";" << midia->getGenero()->getNome() << ";" << midia->getDuracao() << "\n";
            }
        }
        for (Midia *midia : favs)
        {
            if (midia->getTipo() == 'M')
            {
                favoritos << assinante->getCodigo() << ";";
                favoritos << "Música;" << midia->getCodigo() << ";" << midia->getGenero()->getNome() << ";" << midia->getDuracao() << "\n";
            }
        }
    }
    favoritos << "\n";

    favoritos.close();
}

// Escreve arquivo 4-backup.txt
void PlataformaDigital::geraRelatorioBackup()
{
    ofstream backup;

    backup.open("4-backup.txt");
    this->assinantes.sort(ordenaCrescPorCodigo<Assinante>);
    backup << "Usuários:\n\n";
    if (backup.is_open())
    {
        for (Assinante *it : this->assinantes)
        {
            it->imprimeNoArquivo(backup);
        }
        for (Produtor *it : this->produtoresCadastrados)
        {
            backup << it->getCodigo() << ";" << it->getNome() << "\n";
        }

        backup << "\nMídias:\n\n";

        for (Midia *itM : this->produtosCadastrados)
        {
            itM->imprimeNoArquivo(backup);
        }
    }
    backup.close();
}

// Calcula o tempo total das mídias dos assinantes da plataforma
float PlataformaDigital::tempoConsumido()
{
    float tempoTotal = 0;

    for (Assinante *itUsuario : this->assinantes)
    {
        tempoTotal += itUsuario->calculaTempoFavs();
    }

    return tempoTotal;
}

pair<float, Midia::Genero *> PlataformaDigital::generoMaisEscutado()
{
    this->generosCadastrados.sort(ordenaDecrescPorFavoritado<Midia::Genero>);
    pair<float, Midia::Genero *> par;
    if (this->generosCadastrados.begin() != this->generosCadastrados.end())
    {
        par = make_pair((*this->generosCadastrados.begin())->getEscutado(), *this->generosCadastrados.begin());
    }
    else
    {
        par.first = 0;
        par.second = NULL;
    }
    return par;
}
