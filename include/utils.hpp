#pragma once
#ifndef _utils_
#define _utils_
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string floatPontoParaVirgula(float floatComPonto);
string converteParaMinusculas(string nome);

template <typename clss>
bool ordenaPorNome(clss *prod1, clss *prod2)
{
    string nomeProd1 = converteParaMinusculas(prod1->getNome());
    string nomeProd2 = converteParaMinusculas(prod2->getNome());

    if (nomeProd1.compare(nomeProd2) < 0) // Comparando duas strings em minúsculo
    {
        return 1;
    }

    return 0;
}

template <typename clss>
bool ordenaDecrescPorFavoritado(clss *prod1, clss *prod2)
{
    if (prod1->getFavoritado() > prod2->getFavoritado())
    {
        return 1;
    }
    return 0;
}

template <typename clss>
bool ordenaDecrescPorEscutado(clss *prod1, clss *prod2)
{
    if (prod1->getEscutado() > prod2->getEscutado())
    {
        return 1;
    }
    return 0;
}

template <typename clss>
bool ordenaCrescPorCodigo(clss *prod1, clss *prod2)
{
    if (prod1->getCodigo() < prod2->getCodigo())
    {
        return 1;
    }
    return 0;
}

template <typename clss>
bool ordenaDecrescPorCodigo(clss *prod1, clss *prod2)
{
    if (prod1->getCodigo() > prod2->getCodigo())
    {
        return 1;
    }
    return 0;
}

#endif
