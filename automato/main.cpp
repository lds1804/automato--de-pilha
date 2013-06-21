#include <stdio.h>
#include <string>
#include "automato2.h"
#include <iostream>
#include "pilha.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;



int main()

{
    automato aut;


    string line;
    int estado,inicial,fim;
    bool fimb,inicialb;



    fstream file;
    file.open("entrada.txt",ios::in);

    while(file.eof()==false)
    {
        int tam;
        getline(file,line);
        stringstream ss(line);
        ss>>tam;
//    cout<<line;
//    cout<<tam;
        for(int i=0; i<tam; i++)
        {
            getline(file,line);
            int j;
//       for(j=0;(line[j]!=' ');j++)
//       {
//
//       }
//       cout<<"j="<<j;
            //cout <<"linha:"<<line;
            std::string charatual = line.substr (0,1);
            //cout<<"caracter atual: "<< charatual<<endl;
            stringstream ss(charatual);
            ss>>estado;

            std::string fimc = line.substr (2,1);
            //cout<<"fimc: "<< fimc<<endl;
            fim=int (fimc[0])-48;
            //cout<<"fim"<<fim<<endl;

            if(fim==1)
                fimb=true;
            else fimb=false;

            std::string inicialc = line.substr (4,1);
            //cout<<"incialc: "<<inicialc <<endl;
            inicial=int (inicialc[0])-48;


            if(inicial==1)
                inicialb=true;
            else inicialb=false;

            //cout<<"fim "<<fimb<<"estado "<<estado<<"inicial "<<inicialb<<endl;

            aut.insereestado(fimb,estado,inicialb);




        }

        getline(file,line);
        tam=int(line[0])-48;
        //cout<<"linha alfabeto"<<line<<endl;

        for(int i=0; i<tam; i++)
        {
            getline(file,line);
            //cout<<"linha alfabeto for"<<line<<endl;

            aut.inserealfabeto(line);


        }

        getline(file,line);
        tam=int(line[0])-48;
        //cout<<"tam"<<tam<<endl;

        for(int i=0; i<tam; i++)
        {
            getline(file,line);
            //cout<<"linha transicao for"<<line<<endl;

            std::string origemb2 = line.substr (0,1);
            //cout<<"fimc: "<< fimc<<endl;
            int origem=int (origemb2[0])-48;

            std::string destino2 = line.substr (2,1);
            //cout<<"fimc: "<< fimc<<endl;
            int destino=int (destino2[0])-48;

            std::string ch = line.substr (4,6);
            //cout<<"fimc: "<< fimc<<endl;

            //cout<<"origem:"<<origem<<"destino:"<<destino<<"ch:"<<ch<<endl;

            aut.inseretransicao(origem,destino,ch);





        }


        getline(file,line);
        tam=int(line[0])-48;


        for(int i=0; i<tam; i++)
        {
            getline(file,line);
            aut.consomecadeia(line);
            //cout<<"linha"<<line;
            getchar();

        }
        tam=0;

    }











//    automato aut;
//    automato aut2;
//    automato aut3;
//
//    aut.insereestado(false,0,true);
//    aut.insereestado(false,1,false);
//    aut.insereestado(false,2,false);
//    aut.insereestado(false,3,false);
//    aut.insereestado(true,4,false);
//    aut.insereestado(true,5,false);
//    aut.insereestado(true,6,false);
//    aut.insereestado(true,7,false);
//
//    aut.inserealfabeto("l");
//    aut.inserealfabeto("_");
//    aut.inserealfabeto("e");
//    aut.inserealfabeto("d");
//    aut.inserealfabeto("outros");
//
//    aut.inseretransicao(0,1,"l");
//    aut.inseretransicao(1,2,"_");
//    aut.inseretransicao(1,3,"e");
//    aut.inseretransicao(2,4,"l");
//    aut.inseretransicao(2,5,"d");
//    aut.inseretransicao(3,6,"l");
//    aut.inseretransicao(3,7,"d");
//    aut.inseretransicao(4,3,"e");
//    aut.inseretransicao(4,2,"_");
//    aut.inseretransicao(5,3,"e");
//    aut.inseretransicao(5,2,"_");
//    aut.inseretransicao(6,3,"e");
//    aut.inseretransicao(6,2,"_");
//    aut.inseretransicao(7,3,"e");
//    aut.inseretransicao(7,2,"_");
//
//
//
//    aut.imprimeaut();
//
//    aut.consomecadeia("l_lel_d");
//    aut.consomecadeia("ledel_l");
//    aut.consomecadeia("l_d_le");
//    aut.consomecadeia("ledel_");
//    aut.consomecadeia("ledel_a");
//
//    aut2.insereestado(false,0,true);
//    aut2.insereestado(false,1,false);
//    aut2.insereestado(false,2,false);
//    aut2.insereestado(false,3,false);
//    aut2.insereestado(false,4,false);
//    aut2.insereestado(false,5,false);
//    aut2.insereestado(false,6,false);
//    aut2.insereestado(true,7,false);
//
//    aut2.inserealfabeto("a");
//    aut2.inserealfabeto("b");
//    aut2.inserealfabeto("e");
//
//    aut2.inseretransicao(0,1,"e");
//    aut2.inseretransicao(0,4,"a");
//    aut2.inseretransicao(1,2,"a");
//    aut2.inseretransicao(2,2,"b");
//    aut2.inseretransicao(2,3,"a");
//    aut2.inseretransicao(3,7,"e");
//    aut2.inseretransicao(4,5,"b");
//    aut2.inseretransicao(5,5,"a");
//    aut2.inseretransicao(5,6,"b");
//    aut2.inseretransicao(6,7,"e");
//
//    aut2.imprimeaut();
//    aut2.consomecadeia("eabbbbae");
//    aut2.consomecadeia("abaaaabe");
//    aut2.consomecadeia("eabbbaa");
//    aut2.consomecadeia("abaaaba");
//
//    aut3.insereestado(false,0,true);
//    aut3.insereestado(false,1,false);
//    aut3.insereestado(true,2,false);
//    aut3.insereestado(false,3,false);
//    aut3.insereestado(false,4,false);
//    aut3.insereestado(true,5,false);
//    aut3.insereestado(false,6,false);
//
//    aut3.inserealfabeto("0");
//    aut3.inserealfabeto("1");
//
//    aut3.inseretransicao(0,1,"0");
//    aut3.inseretransicao(0,3,"1");
//    aut3.inseretransicao(1,1,"0");
//    aut3.inseretransicao(1,2,"1");
//    aut3.inseretransicao(2,4,"1");
//    aut3.inseretransicao(2,1,"0");
//    aut3.inseretransicao(3,4,"1");
//    aut3.inseretransicao(3,1,"0");
//    aut3.inseretransicao(4,4,"1");
//    aut3.inseretransicao(4,5,"0");
//    aut3.inseretransicao(5,5,"0");
//    aut3.inseretransicao(5,6,"1");
//    aut3.inseretransicao(6,5,"0");
//    aut3.inseretransicao(6,4,"1");
//
//    aut3.consomecadeia("000010110");
//    aut3.consomecadeia("11110001010");
//    aut3.consomecadeia("0111001011");
//    aut3.consomecadeia("0001001111");
//    aut3.consomecadeia("1111001001");
//
//    aut3.imprimeaut();
//
//    automato aut4;
//
//    aut4.insereestado(false,0,true);
//    aut4.insereestado(false,1,false);
//    aut4.insereestado(false,2,false);
//    aut4.insereestado(false,3,false);
//    aut4.insereestado(false,4,false);
//    aut4.insereestado(false,5,false);
//    aut4.insereestado(false,6,false);
//    aut4.insereestado(false,7,false);
//    aut4.insereestado(true,8,false);
//
//    aut4.inserealfabeto("a");
//    aut4.inserealfabeto("b");
//
//    aut4.inseretransicao(0,1,"a");
//    aut4.inseretransicao(0,0,"b");
//    aut4.inseretransicao(1,2,"a");
//    aut4.inseretransicao(1,0,"b");
//    aut4.inseretransicao(2,2,"a");
//    aut4.inseretransicao(2,3,"b");
//    aut4.inseretransicao(3,4,"a");
//    aut4.inseretransicao(3,0,"b");
//    aut4.inseretransicao(4,5,"a");
//    aut4.inseretransicao(4,0,"b");
//    aut4.inseretransicao(5,6,"a");
//    aut4.inseretransicao(5,3,"b");
//    aut4.inseretransicao(6,2,"a");
//    aut4.inseretransicao(6,7,"b");
//    aut4.inseretransicao(7,4,"a");
//    aut4.inseretransicao(7,8,"b");




    //aut4.consomecadeia("bbaabaaabb");
    //aut4.consomecadeia("bbbaaaaabaaabb");
    //aut4.consomecadeia("baaaabaaaa");
    //aut4.consomecadeia("babaaabaa");
    //aut4.consomecadeia("bbabaaabaaab");

    //aut4.imprimeaut();



//    aut.insereestado(false,0,true);
//    aut.insereestado(false,1,false);
//    aut.insereestado(false,2,false);
//    aut.insereestado(true,3,false);
//    aut.insereestado(true,4,false);
//    aut.insereestado(false,5,false);
//
//    aut.inserealfabeto("T");
//    aut.inserealfabeto("I");
//    aut.inserealfabeto("<");
//    aut.inserealfabeto(">");
//    aut.inserealfabeto("N");
//    aut.inserealfabeto("outros");
//
//    aut.inseretransicao(0,1,"T");
//    aut.inseretransicao(1,4,"I");
//    aut.inseretransicao(2,5,">");
//    aut.inseretransicao(3,1,"outros");
//    aut.inseretransicao(4,2,"<");
//    aut.inseretransicao(4,1,"outros");
//    aut.inseretransicao(5,2,"outros");
//    aut.inseretransicao(5,3,"N");
//
//    aut.consomecadeia("TI,I<N>,I,I<N,N,N>,I<N>");

    aut.imprimeaut();



    return 0;

}
