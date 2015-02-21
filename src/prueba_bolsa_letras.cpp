/**
  * @file prueba_bolsa_letras.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include "Bolsa_letras.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

#define TOTAL 10

using namespace std;

int main(int argc, char const *argv[]){

    if (argc!=2){
        cout<<"Dime el nombre del fichero con las letras"<<endl;
        return 0;
    }

    ifstream f (argv[1]);

    if (!f){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    ConjuntoLetras conjunto;
    f>> conjunto;

    BolsaLetras bolsa;
    srand(time(NULL));

    for(int i = 0; i < TOTAL; i++){
        bolsa.aniade_letra(conjunto.GetLetraAleatoria());
    }
    cout << "Letras que estan en la bolsa:";
    for(char i = 'A'; i <= 'Z'; i++){
        if(bolsa.pertenece(i)){
            cout << i << " ";
        }
    }
    cout << endl;


    return 0;
}