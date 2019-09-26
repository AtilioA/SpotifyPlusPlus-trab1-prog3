#ifndef _USUARIO_
#define _USUARIO_
#include <iostream>

using namespace std;

class Usuario{
    protected:
        string nome;
    public:
        string getNome();
        void setNome(string nome);
};

#endif