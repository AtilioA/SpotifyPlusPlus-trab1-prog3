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
    int intDur;
    string primeiroGenero;
    int temporada;
    string album;
    int codAlbum;
    int ano;
    string primeiraLinha;
    Midia *produto;
    list<int> produtores;
    // list<Produtor*> produtores;
    Album *albumNovo;
    //list<Podcast *> *podcasts;
    // list<Album *> *albunsDeArtista;
    int qtdGeneros = 0;
    getline(infile, primeiraLinha); // Ignorando primeira linha
    while (!infile.eof())
    {

        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);
        
        linhaAtualStream >> cod; // Verificar se é número (Erro 2)
        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, nome, ';');
        retiraCR(nome);
        linhaAtualStream >> tipo;
        linhaAtualStream.ignore(1, ';');
        linhaAtualStream >> codProd;
        produtores.push_back(codProd);

        if (linhaAtualStream.peek() == ',')
        {
            linhaAtualStream.ignore(1, ',');
        }

        while (linhaAtualStream.peek() != ';')
        {
            linhaAtualStream >> codProd;
            produtores.push_back(codProd);
            if(linhaAtualStream.peek() == -1){
                break;
            }
            if (linhaAtualStream.peek() == ',')
            {
                linhaAtualStream.ignore(1, ',');
            }
        }
        //cout << cod << "\n";
        linhaAtualStream.ignore(1, ';');
        linhaAtualStream >> intDur;
        linhaAtualStream.ignore(1, ',');
        linhaAtualStream >> floatDur;
        floatDur = intDur + (floatDur / 100); // Juntando parte inteira e decimal da duração
        linhaAtualStream.ignore(1, ';');
        getline(linhaAtualStream, primeiroGenero, ';');
        for (string::iterator itGenero = primeiroGenero.begin(); itGenero != primeiroGenero.end(); itGenero++)
        {
            if ((*itGenero) == ',') // Zeradsse precisa disso mesmo?
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
            linhaAtualStream >> temporada;
            linhaAtualStream.ignore(1, ';');
        }
        else
        {
            temporada = -1;
            linhaAtualStream.ignore(1, ';');
        }
        getline(linhaAtualStream, album, ';');
        linhaAtualStream >> codAlbum;
        linhaAtualStream.ignore(1, ';');
        linhaAtualStream >> ano;
        
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
            cerr << "Inconsistências na entrada (não achou gênero)\n";
            exit(3);
        }

        // Criando objeto de acordo com Tipo
        if (tipo == 'P')
        {
            produto = new Podcast(nome, cod, (*itGeneros), temporada, floatDur);
        }
        else
        {
            produto = new Musica(nome, cod, (*itGeneros), floatDur, ano);
        }
        (*itGeneros)->adicionaMidia(produto);
        this->produtosCadastrados.push_back(produto);

        list<Album*>::iterator itAlbuns;

        for(itAlbuns = this->albunsCadastrados.begin(); itAlbuns != this->albunsCadastrados.end(); itAlbuns++){
            if((*itAlbuns)->getCodigo() == codAlbum){
                albumNovo = (*itAlbuns);
                break;
            }
        }

        if(itAlbuns == this->albunsCadastrados.end() && !album.empty()){
            albumNovo = new Album(album, codAlbum, floatDur, ano, 1);
            this->albunsCadastrados.push_back(albumNovo);
        }

        size_t achastesProd = 0;
        for (list<int>::iterator itProdutores = produtores.begin(); itProdutores != produtores.end(); itProdutores++)
        {
            for (list<Produtor *>::iterator itProdutoresCad = this->produtoresCadastrados.begin(); itProdutoresCad != this->produtoresCadastrados.end(); itProdutoresCad++)
            {
                if ((*itProdutores) == (*itProdutoresCad)->getCodigo())
                {
                    achastesProd++;
                    produto->adicionaProdutor((*itProdutoresCad));
                    (*itProdutoresCad)->novoProduto(produto);

                    if (tipo == 'P')
                    {
                        ((Podcaster *)(*itProdutoresCad))->inserePodcast((Podcast *)produto);
                    }
                    else
                    {
                        if (!album.empty())
                        {
                            albumNovo->adicionaMusica((Musica *)produto);
                            if (((Artista *)(*itProdutoresCad))->procuraAlbum(album) == NULL)
                            {
                                ((Artista *)(*itProdutoresCad))->insereAlbum(albumNovo);
                            }
                        }
                    }
                }
            }
        }

        if (achastesProd != produtores.size()) // não sei se tá certo, é só uma ideia
        {
            cerr << "Inconsistências na entrada (não achou todos os produtores)\n";
            exit(3);
        }
        produtores.clear();
        if(infile.peek() == -1){
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
        if(infile.peek() == -1){
            break;
        }
    }
}

void PlataformaDigital::imprimeGeneros()
{
    for (list<Midia::Genero *>::iterator it = this->generosCadastrados.begin(); it != this->generosCadastrados.end(); it++)
    {
        cout << (*it)->getSigla() << ";" << (*it)->getNome() << endl;
    }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile)
{
    // char teste;
    string primeiraLinha;
    int cod = 0;
    int favoritoAtual = 0;
    list<int> favoritos;
    getline(infile, primeiraLinha); // Ignorando primeira linha
    list<Assinante *>::iterator itAssinante;
    string linhaAtual;
    while (!infile.eof())
    {
        getline(infile, linhaAtual);
        stringstream linhaAtualStream(linhaAtual);
        linhaAtualStream >> cod;
        linhaAtualStream.ignore(1, ';');
        if (linhaAtualStream.peek() == -1)
        {
            continue;
        }

        linhaAtualStream >> favoritoAtual;
        favoritos.push_back(favoritoAtual);
        while (linhaAtualStream.peek() == ',')
        {
            linhaAtualStream.ignore(1, ',');
            linhaAtualStream >> favoritoAtual;
            favoritos.push_back(favoritoAtual);
        }

        for (itAssinante = this->assinantes.begin(); itAssinante != this->assinantes.end(); itAssinante++)
        {
            if ((*itAssinante)->getCodigo() == cod)
            {
                break;
            }
        }

        if(itAssinante == this->assinantes.end()){ // dps vamo tentar fazer com try catch
            cerr << "Inconsistências na entrada (código não pertence a nenhum assinante)\n";
            exit(3);
        }

        for (list<int>::iterator itFavs = favoritos.begin(); itFavs != favoritos.end(); itFavs++)
        {
            for (list<Midia *>::iterator itFavsM = this->produtosCadastrados.begin(); itFavsM != this->produtosCadastrados.end(); itFavsM++)
            {
                if (*itFavs == (*itFavsM)->getCodigo())
                {
                    (*itAssinante)->insereFavoritos((*itFavsM));
                }
            }
        }
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
        linhaAtualStream >> cod; // Verificar se é número (Erro 2)
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
            cerr << "Erro de formatação\n";
            exit(2);
            break;
        }
    }
    this->assinantes.sort(ordenaPorNome<Assinante>);
    this->produtoresCadastrados.sort(ordenaPorNome<Produtor>);
}

void PlataformaDigital::imprimeUsuarios()
{

    for (list<Assinante *>::iterator it = this->assinantes.begin(); it != this->assinantes.end(); it++)
    {
        cout << (*it)->getCodigo() << ";" << (*it)->getNome() << "\n";
    }
}

void PlataformaDigital::imprimeProdutores()
{
    for (list<Produtor *>::iterator it = this->produtoresCadastrados.begin(); it != this->produtoresCadastrados.end(); it++)
    {
        cout << (*it)->getCodigo() << ";" << (*it)->getNome() << "\n";
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
        for (list<Produtor *>::iterator it = this->produtoresCadastrados.begin(); it != this->produtoresCadastrados.end(); it++)
        {
            (*it)->imprimeNoArquivo(midias_prods);
            //cout << "quero saber pq n chama\n";
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

}

void PlataformaDigital::geraRelatorios()
{
}

float PlataformaDigital::tempoConsumido(){
    float tempoTotal = 0;
    for(Assinante* itUsuario: this->assinantes){
        for(Midia* itMidia: itUsuario->getFavoritos()){
            tempoTotal += itMidia->getDuracao();
        }
    }
    return tempoTotal;
}
