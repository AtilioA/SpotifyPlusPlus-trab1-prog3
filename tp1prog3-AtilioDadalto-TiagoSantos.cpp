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
                cout << "--GENERO--    " << argv[i + 1] << endl;
                gen = argv[i + 1];
                i++;
                break;
            case 'u':
                cout << "--USUARIO--   " << argv[i + 1] << endl;
                user = argv[i + 1];
                i++;
                break;
            case 'm':
                cout << "--MIDIA--     " << argv[i + 1] << endl;
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
    // cout << "\n|Usuarios: " << user << "| |Genero: " << gen << "| |Midia: " << midia << "| |Favoritos: " << favs << "|\n";

    // Abrindo arquivos de entrada
    ifstream fileUser;
    ifstream fileGen;
    ifstream fileMidia;
    ifstream fileFavs;
    fileUser.open(user.c_str());
    fileGen.open(gen.c_str());
    fileMidia.open(midia.c_str());
    fileFavs.open(favs.c_str());
    if (argv[1] == NULL || !fileUser.is_open() || !fileGen.is_open() || !fileMidia.is_open() || !fileFavs.is_open()) // Verificação de arquivos (precisa do argv[1] == NULL?)
    {
        /* Erros de entrada e saída de dados como, por exemplo, o arquivo especificado não existir
        * ou o programa não ter permissão para ler ou escrever em um arquivo
        */
       cout << argv[1] << fileGen.is_open() << fileMidia.is_open() << fileGen.is_open() << fileFavs.is_open() << endl;

        cerr << "Erro de I/O\n";
        exit(1);
    }

    PlataformaDigital *spotifyzada = new PlataformaDigital("Spotify==");
    cout << "Plataforma digital criada.\n";

    spotifyzada->carregaArquivoGeneros(fileGen);
    cout << "Generos:\n";
    spotifyzada->imprimeGeneros();

    spotifyzada->carregaArquivoUsuarios(fileUser);
    cout << "\nUsuarios:\n";
    spotifyzada->imprimeUsuarios();

    cout << "\nProdutores:\n";
    spotifyzada->imprimeProdutores();
    cout << "\nMidias:\n";
    spotifyzada->carregaArquivoMidias(fileMidia);

    cout << "\nQuantidade de midias: " << Midia::qtdProdutos << "\n";

    spotifyzada->carregaArquivoFavoritos(fileFavs);
    // spotifyzada->imprimeUsuarios();

    cout << "Tempo total: " << spotifyzada->tempoConsumido() << " minutos ou \n";
    cout << "Tempo total: " << spotifyzada->tempoConsumido() / 60 << " horas\n";

    spotifyzada->geraRelatorioMidiasProdutores();

    fileUser.close();
    fileGen.close();
    fileMidia.close();
    fileFavs.close();
    delete spotifyzada;
    return 0;
}
