#include <iostream>
#include <cstdlib>
#include <fstream>
#include "include/Artista.hpp"
#include "include/Assinante.hpp"
#include "include/Album.hpp"
#include "include/Midia.hpp"
#include "include/Musica.hpp"
#include "include/PlataformaDigital.hpp"
#include "include/Podcast.hpp"
#include "include/Podcaster.hpp"
#include "include/Produtor.hpp"
#include "include/Usuario.hpp"

using namespace std;

int Midia::qtdProdutos = 0;

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 9)
        {
            throw "Erro de I/O";
        }
    }
    catch (const char *msg)
    {
        cerr << msg << "\n";
        exit(1);
    }

    string gen;
    string user;
    string midia;
    string favs;

    for (int i = 1; argv[i] != NULL; i++)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1]) // Switch para identificar argumentos passados pelo terminal
            {
            case 'g':
                cout << "--GÊNEROS--   " << argv[i + 1] << endl;
                gen = argv[i + 1];
                i++;
                break;
            case 'u':
                cout << "--USUÁRIOS--  " << argv[i + 1] << endl;
                user = argv[i + 1];
                i++;
                break;
            case 'm':
                cout << "--MÍDIAS--    " << argv[i + 1] << endl;
                midia = argv[i + 1];
                i++;
                break;
            case 'f':
                cout << "--FAVORITOS-- " << argv[i + 1] << endl;
                favs = argv[i + 1];
                i++;
                break;
            default:
                cerr << "OPÇÃO NÃO RECONHECIDA\n";
                break;
            }
        }
    }

    // Abrindo arquivos de entrada
    ifstream fileUser;
    ifstream fileGen;
    ifstream fileMidia;
    ifstream fileFavs;
    fileUser.open(user.c_str());
    fileGen.open(gen.c_str());
    fileMidia.open(midia.c_str());
    fileFavs.open(favs.c_str());

    try
    {
        if (argv[1] == NULL || !fileUser.is_open() || !fileGen.is_open() || !fileMidia.is_open() || !fileFavs.is_open())
        {
            cout << argv[1] << fileGen.is_open() << fileMidia.is_open() << fileGen.is_open() << fileFavs.is_open() << "\n";

            throw "Erro de I/O";
        }
    }
    catch (const char *msg)
    {
        fileUser.close();
        fileGen.close();
        fileMidia.close();
        fileFavs.close();
        cerr << msg << "\n";
        exit(1);
    }

    PlataformaDigital *spotifyzada = new PlataformaDigital("Spotify==");
    cout << "Plataforma digital criada.\n";

    cout << "\nCarregando gêneros...\n";
    spotifyzada->carregaArquivoGeneros(fileGen);
    cout << "Gêneros OK!\n";
    // spotifyzada->imprimeGeneros();

    cout << "Carregando usuários...\n";
    spotifyzada->carregaArquivoUsuarios(fileUser);
    cout << "Usuários OK!\n";
    // spotifyzada->imprimeUsuarios();

    // cout << "\nProdutores:\n";
    // spotifyzada->imprimeProdutores();
    cout << "Carregando mídias...\n";
    spotifyzada->carregaArquivoMidias(fileMidia);
    cout << "Mídias OK!\n";

    cout << "Carregando favoritos...\n";
    spotifyzada->carregaArquivoFavoritos(fileFavs);
    cout << "Favoritos OK!\n";

    cout << "\nQuantidade de mídias: " << Midia::qtdProdutos << "\n";
    cout << "Tempo total: " << spotifyzada->tempoConsumido() << " minutos.\n";

    cout << "\nGerando relatório de produtores...\n";
    spotifyzada->geraRelatorioMidiasProdutores();
    cout << "Relatório de produtores OK!\n";

    cout << "Gerando relatório de estatísticas...\n";
    spotifyzada->geraRelatorioEstatisticas();
    cout << "Relatório de estatísticas OK!\n";

    cout << "Gerando relatório de backup...\n";
    spotifyzada->geraRelatorioBackup();
    cout << "Relatório de backup OK!\n";

    cout << "Gerando relatório de favoritos...\n";
    spotifyzada->geraRelatorioFavoritos();
    cout << "Relatório de favoritos OK!\n";

    fileUser.close();
    fileGen.close();
    fileMidia.close();
    fileFavs.close();
    delete spotifyzada;

    return 0;
}
