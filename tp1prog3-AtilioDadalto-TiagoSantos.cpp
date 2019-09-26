#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    for(int i = 1; argv[i] != NULL; i++){
        if(argv[i][0] == '-'){
            switch(argv[i][1]){
                case 'g':
                    cout << "--GENERO-- " << argv[i + 1] << endl;
                    i++;
                    break;
                case 'u':
                    cout << "--USUARIO-- " << argv[i + 1] << endl;
                    i++;
                    break;
                case 'm':
                    cout << "--MIDIA-- " << argv[i + 1] << endl;
                    i++;
                    break;
                case 'f':
                    cout << "--FAVORITOS-- " << argv[i + 1] << endl;
                    i++;
                    break;
                default:
                    cerr << "OPÇÃO NÃO RECONHECIDA" << endl;
                    break;
            }
        }
    }
    if (argv[1] == NULL)
    {
        printf("Entrada de buscas invalida.\n");
        exit(1);
    }
    return 0;
}
