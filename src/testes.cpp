#include <iostream>
#include <cstdlib>
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
    if (argv[1] == NULL)
    {
        printf("Entrada de buscas invalida.\n");
        exit(1);
    }
    Produtor * prod = new Produtor("Ramon fodase");
    Midia * musi = new Musica("Opa", 12, "pancadão brabo", "00:00:01", 2077);
    cout << prod->getNome() << endl;
    vector<Midia*> seila;
    seila.push_back(musi);
    prod->setProdutosDesenvolvidos(seila);
    cout << prod->getProdutosDesenvolvidos().at(0)->getGenero().getNome() << endl;
    delete prod;
    delete musi;
    return 0;
}
