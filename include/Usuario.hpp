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

template <typename clss>
bool ordenaPorNome(clss *prod1, clss *prod2)
{
    if (prod1->getNome().compare(prod2->getNome()) < 0)
    {
        return 1;
    }
    return 0;
};

template <typename clss>
bool ordenaPorCodigo(clss *prod1, clss *prod2)
{
    if (prod1->getCodigo() < prod2->getCodigo())
    {
        return 1;
    }
    return 0;
};

#endif
