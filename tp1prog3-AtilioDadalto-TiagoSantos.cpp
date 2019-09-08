#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /* Validação de argumentos de entrada */
    if (argv[1] == NULL)
    {
        printf("Entrada de buscas invalida.\n");
        exit(1);
    }
    return 0;
}
