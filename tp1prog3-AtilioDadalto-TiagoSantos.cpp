#include <iostream>
#include <cstdlib>
#include <fstream>
#include "./include/Artista.hpp"
#include "./include/Assinante.hpp"
#include "./include/Album.hpp"
#include "./include/Midia.hpp"
#include "./include/Musica.hpp"
#include "./include/PlataformaDigital.hpp"
#include "./include/Podcast.hpp"
#include "./include/Podcaster.hpp"
#include "./include/Produtor.hpp"
#include "./include/Usuario.hpp"

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
    ifstream file_user;
    ifstream file_gen;
    ifstream file_midia;
    ifstream file_favs;
    file_user.open(user.c_str(), ios::in);
    file_gen.open(gen.c_str(), ios::in);
    file_midia.open(midia.c_str(), ios::in);
    file_favs.open(favs.c_str(), ios::in);
    if (argv[1] == NULL || !file_gen.is_open() || !file_midia.is_open() || !file_gen.is_open() || !file_favs.is_open())
    {
        //printf("Entrada de buscas invalida.\n");
        cout << "Entrada de buscas invalida." << endl;
        exit(1);
    }
    Produtor * prod = new Produtor("Ramon fodase", 13);
    //Midia * musi = new Musica("Opa", 12, "pancadão brabo", "00:00:01", 2077);
    cout << prod->getNome() << endl;
    vector<Midia*> seila;
    //seila.push_back(musi);
    prod->setProdutosDesenvolvidos(seila);
    cout << prod->getProdutosDesenvolvidos().at(0)->getGenero().getNome() << endl;
    delete prod;
    //delete musi;
    string test;
    string nome;
    string tipo;
    int cod;
    vector<Usuario*> vetorzin;
    while(!file_user.eof()){
        file_user >> cod;
        cout << cod << endl;
        file_user.ignore(1, ';');
        getline(file_user, tipo, ';');
        cout << tipo << endl;
        getline(file_user, nome);
        cout << nome << endl;
        if(tipo == "AS"){
            vetorzin.push_back(new Assinante(nome, cod));
        }else if(tipo == "PC"){
            vetorzin.push_back(new Podcaster(nome, cod));
        }
    }
    file_user.close();
    file_gen.close();
    file_midia.close();
    file_favs.close();
    return 0;
}
