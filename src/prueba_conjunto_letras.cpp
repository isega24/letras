/**
  * @file prueba_conjunto_letras.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include "Conjunto_letras.h"
#include <iostream>
#include <fstream>

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

    cout << conjunto;

    Letra letra = conjunto.GetLetraAleatoria();

    cout << "Esta es una letra:\n";
    cout << letra.getletra() << "\t" << letra.getveces() << "\t"<< letra.getpuntuacion() << endl;
    return 0;
}