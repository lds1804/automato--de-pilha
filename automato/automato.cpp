#include "automato2.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;




void automato::insereestado(bool fim,int iden,bool ini) // adiciona um estado ao automato
{
    estado* pointer;
    pointer = new estado; // cria novo estado
    pointer->setfinal(fim);// configura estado com os parametros passados
    pointer->setini(ini);
    pointer->setid(iden);
    nest++;
    estados[nest]=pointer;
    if(ini==true)       // se o boolenao ini passado for true configura o ponteiro de estado inicial do automato para o ponteiro do estado atual
    {
        estini=pointer;
    }



}

void automato::imprimeaut() // imprime o automato
{





    cout <<"             ";
    for(int j=0; j<=alfab->getncar(); j++) // imprime os membros do alfabeto do automato
    {
        cout << " "<<alfab->getchar(j)<<" ";

    }
    cout <<endl;

    for(int i=0; estados[i]!=NULL; i++) //imprime o identificador dos estados e seus atributos
    {



        cout << estados[i]->getid()<<" ";

        if(estados[i]->getfinal()==true)
            cout <<"  (Final) ";


        else if(estados[i]->getinicial()==true)
            cout << "(Inicial) ";
        else  cout<<"          ";


        for(int j=0; j<=alfab->getncar(); j++)
        {
            if(estados[i]->gettransicao(j)!=-1)
                cout <<"  "<< estados[i]->gettransicao(j);
            else cout <<"   ";
        }

        getchar();

    }










}



automato::automato() //configura id e numero de estados e seta o vetor de estados com todos os valores NULL e cria um novo alfabeto
{


    nest=-1;

    for(int i=0; i<1000; i++)
    {
        estados[i]=NULL;


    }

    estadoatual=NULL;
    estini=NULL;
    alfab=new alfabeto();




}

void automato::inseretransicao(int idorigem,int iddest, string caractere) // insere transicao dentro de um estado
{
    estado* origem;
    int index=-1;


    for(int i=0; i<=nest; i++) // procura dentro do vetor de estados o estado que corresponde ao id de origem e atribui a origem este ponteiro
    {
        if(idorigem==estados[i]->getid())
            origem=estados[i];
    }

    for(int i=0; i<=alfab->getncar(); i++) // procura dentro do vetor de caracteres do alfabeto o indice em que o caractere atual esta contido
    {
        if(caractere==alfab->getchar(i))
            index=i;

    }

    origem->inseretransicao(iddest,index); // com o indice e o ponteiro de origem insere a transicao



}

void automato::inserealfabeto(string caractere) // insere caractere no alfabeto
{

    alfab->inserecaractere(caractere);

}

void automato::consomecadeia(string cadeia)
{
    ofstream myfile;
    myfile.open("saida.txt",ios::app);
    myfile.clear();
    string charatual;
    estini=estados[0]; // configura estado inicial
    estadoatual=estados[0]; // configura estado atual
    int tam;
    tam=cadeia.size();
    bool transitou=true; // booleano que e utilizado para verificar se o automato transitou com dada cadeia
    myfile<<"Cadeia: "<<cadeia<<endl;

    for(int i=0; i<tam && transitou==true; i++)
    {
        charatual=cadeia[i]; // pega caractere atual
        myfile << "Estado atual "<<estadoatual->getid()<<" "<<"caracter atual "<< charatual;
        if(alfab->pertencealfabeto(charatual)==true) // verifica se pertence ao alfabeto
        {
            int indice=alfab->getindice(charatual); // pega o  indice do caractere atual detnro do vetor de caracteres do alfabeto
            int indiceprox= estadoatual->gettransicao(indice);// com o indice obtido acima utiliza a funcao gettransicao para o estado atual e obtem um inteiro que indica o identificador do proximo estado
            myfile <<" transita para "<<indiceprox<<endl; //
            if(indiceprox!=-1)
                estadoatual=estados[indiceprox]; // configura o estado atual utilizando o indice encontrado acima
            else transitou=false;


        }
        else // entra caso o caractere nao pertencer ao alfabeto
        {
            int j=alfab->getncar();// j recebe o numero de caracteres do alfabeto -1
            int indiceproximoest = estadoatual->gettransicao(j);//com o estado atual e o indice j pega o identificador do proximo estado para o qual o automato tansita
            myfile <<" transita para "<<indiceproximoest<<endl;
            if(indiceproximoest!=-1)
                estadoatual=estados[indiceproximoest]; // configura o estado atual utilizando o indice encontrado acima
            else transitou=false;


        }


    }
    myfile<<"Estado atual " << estadoatual->getid();
    if (estadoatual->getfinal()==true)
        myfile<< " Estado Final"<<endl;
    else myfile <<" Estado nao final"<<endl;

    if(transitou==true &&(estadoatual->getfinal()==true)) // apos o fim do loop verifica se aceita ou rejeita a cadeia se o automato tansitou com todos os caracteres e o estado final é de
        myfile <<"Cadeia aceita"<<endl;                       // aceitaçao entao a cadeia é aceita
    else
        myfile <<"Cadeia nao aceita"<<endl<<endl<<endl;


}


