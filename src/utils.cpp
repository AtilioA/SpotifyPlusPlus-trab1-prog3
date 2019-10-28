#include "../include/utils.hpp"

string converteParaMinusculas(string nome)
{
    string nomeConvertido = nome;

    for (char &c : nomeConvertido)
    {
        c = ::tolower(c);
    }

    return nomeConvertido;
}

string floatPontoParaVirgula(float floatComPonto)
{
    stringstream ss;
    string HC_str;
    int pos;

    ss << floatComPonto;
    getline(ss, HC_str);
    pos = HC_str.find('.');
    if (pos != -1) // Se achar caractere '.'
    {
        // Troca o ponto por uma vírgula
        HC_str.replace(pos, 1, 1, ',');
    }

    return HC_str;
}
