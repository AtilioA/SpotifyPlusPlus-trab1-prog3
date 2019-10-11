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
    for(int i = 1; argv[i] != NULL; i++){
        if(argv[i][0] == '-'){
            switch(argv[i][1]){
                case 'g':
                    cout << "--GENERO-- " << argv[i + 1] << endl;
                    gen = argv[i + 1];
                    i++;
                    break;
                case 'u':
                    cout << "--USUARIO-- " << argv[i + 1] << endl;
                    user = argv[i + 1];
                    i++;
                    break;
                case 'm':
                    cout << "--MIDIA-- " << argv[i + 1] << endl;
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
    cout << "|usuarios: " << user << "| |genero: " << gen << "| |midia: " << midia << "| |favoritos: " << favs << "|" << endl;
    ifstream file_user;
    ifstream file_gen;
    ifstream file_midia;
    ifstream file_favs;
    file_user.open(user.c_str());
    file_gen.open(gen.c_str());
    file_midia.open(midia.c_str());
    file_favs.open(favs.c_str());
    if (argv[1] == NULL || !file_gen.is_open() || !file_midia.is_open() || !file_gen.is_open() || !file_favs.is_open())
    {
        //printf("Entrada de buscas invalida.\n");
        cerr << "Entrada de buscas invalida." << endl;
        exit(1);
    }
    PlataformaDigital* spotifyzada = new PlataformaDigital("spplitfy");
    spotifyzada->carregaArquivoGeneros(file_gen);
    spotifyzada->imprimeGeneros();
    spotifyzada->carregaArquivoUsuarios(file_user);
    cout << "\n\n\n";
    spotifyzada->imprimeUsuarios();
    cout << "\n-\n";
    spotifyzada->imprimeProdutores();
    cout << "\n-\n";
    spotifyzada->carregaArquivoMidias(file_midia);
    cout << Midia::qtdProdutos << "\n";
    file_user.close();
    file_gen.close();
    file_midia.close();
    file_favs.close();
    return 0;
}
