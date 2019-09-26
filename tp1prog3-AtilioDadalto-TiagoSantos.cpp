#include <iostream>
// #include "include/Artista.hpp"
// #include "include/Assinante.hpp"

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
    return 0;
}
