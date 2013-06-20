#ifndef AUTOMATO2_H_INCLUDED
#define AUTOMATO2_H_INCLUDED
#include "estado.h"
#include "alfabeto.h"
#include <string>


class automato

{
private:
    estado* estados[1000];
    estado* estini;
    alfabeto* alfab;
    estado* estadoatual;
    int nest;


public:
    automato();
    void insereestado(bool fim,int iden,bool ini);
    void inserealfabeto(string caractere);
    void setestini(bool ini);
    void setestadoatual(estado* estadoatual);
    void imprimeaut();
    void inseretransicao(int idorigem,int iddest, string caractere);
    void consomecadeia(string cadeia);





};




#endif // AUTOMATO2_H_INCLUDED
