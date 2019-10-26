#pragma once
#ifndef _USUARIO_
#define _USUARIO_
#include <iostream>

using namespace std;

class Usuario
{
    protected:
        string nome;
        int codigo;

    public:
        Usuario();
        Usuario(string _nome, int codigo);

        string getNome();
        void setNome(string nome);
        int getCodigo();
        void setCodigo(int codigo);
};

#endif
