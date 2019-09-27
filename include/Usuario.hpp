#ifndef _USUARIO_
#define _USUARIO_
#include <iostream>

using namespace std;

class Usuario{
    protected:
        string nome;
        int codigo;
    public:
        string getNome();
        void setNome(string nome);
        int getCodigo();
        void setCodigo(int codigo);
};

#endif