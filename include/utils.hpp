#pragma once
#ifndef _utils_
#define _utils_
#include <iostream>

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
bool ordenaDecrescPorFavoritado(clss *prod1, clss *prod2)
{
    if (prod1->getFavoritado() > prod2->getFavoritado())
    {
        return 1;
    }
    return 0;
};

template <typename clss>
bool ordenaDecrescPorEscutado(clss *prod1, clss *prod2)
{
    if (prod1->getEscutado() > prod2->getEscutado())
    {
        return 1;
    }
    return 0;
};

template <typename clss>
bool ordenaCrescPorCodigo(clss *prod1, clss *prod2)
{
    if (prod1->getCodigo() < prod2->getCodigo())
    {
        return 1;
    }
    return 0;
};

template <typename clss>
bool ordenaDecrescPorCodigo(clss *prod1, clss *prod2)
{
    if (prod1->getCodigo() > prod2->getCodigo())
    {
        return 1;
    }
    return 0;
};

#endif
