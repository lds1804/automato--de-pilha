#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED
#include <string>


class estado
{

private:
    bool finalest;
    bool iniest;
    int transicoes[1000];
    int id;
    int ntrans;

public:
    estado();
    void setfinal(bool fim);
    void setini(bool ini);
    void setid(int id2);
    bool getfinal();
    int getid();
    bool getinicial();
    void inseretransicao(int destino, int indice);
    int gettransicao(int i);
    int getntrans();




};


#endif // ESTADO_H_INCLUDED
