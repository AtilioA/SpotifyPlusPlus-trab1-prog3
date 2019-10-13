#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../include/Artista.hpp"
#include "../include/Assinante.hpp"
#include "../include/Album.hpp"
#include "../include/Midia.hpp"
#include "../include/Musica.hpp"
#include "../include/PlataformaDigital.hpp"
#include "../include/Podcast.hpp"
#include "../include/Podcaster.hpp"
#include "../include/Produtor.hpp"
#include "../include/Usuario.hpp"

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
                cerr << "OPÇÃO NÃO RECONHECIDA" << endl;
                break;
            }
        }
    }
    // cout << "\n|Usuarios: " << user << "| |Genero: " << gen << "| |Midia: " << midia << "| |Favoritos: " << favs << "|" << endl;

    // Abrindo arquivos de entrada
    ifstream file_user;
    ifstream file_gen;
    ifstream file_midia;
    ifstream file_favs;
    file_user.open(user.c_str());
    file_gen.open(gen.c_str());
    file_midia.open(midia.c_str());
    file_favs.open(favs.c_str());
    if (/*argv[1] == NULL ||*/ !file_gen.is_open() || !file_midia.is_open() || !file_gen.is_open() || !file_favs.is_open()) // Verificação de arquivos
    {
        cerr << "Entrada de buscas invalida." << endl;
        exit(1);
    }

    PlataformaDigital *spotifyzada = new PlataformaDigital("Spotify==");

    spotifyzada->carregaArquivoGeneros(file_gen);
    cout << "Generos:\n";
    spotifyzada->imprimeGeneros();

    spotifyzada->carregaArquivoUsuarios(file_user);
    cout << "\nUsuarios:\n";

    spotifyzada->imprimeUsuarios();

    cout << "\nProdutores:\n";
    spotifyzada->imprimeProdutores();
    cout << "\nMidias:\n";

    spotifyzada->carregaArquivoMidias(file_midia);
    cout << "\nQuantidade de midias: " << Midia::qtdProdutos << "\n";

    file_user.close();
    file_gen.close();
    file_midia.close();
    file_favs.close();

    return 0;
}
