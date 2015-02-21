#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"
#include "Conjunto_letras.h"
/**
  * @file testdiccionario.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include "Bolsa_letras.h"

  
int main(int argc, char * argv[]){
    if (argc!=2){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.- El fichero con las palabras"<<endl;

        return 0;
    }

    ifstream f(argv[1]);
    cout<<"Cargando diccionario...."<<endl;
    Diccionario D;
    f>>D;
    cout<<"Leido el diccionario..."<<endl;
    cout<<D;

    int longitud;

    cout<<"Dime la longitud de las palabras que quieres ver: ";
    cin>>longitud;
    vector<string> v=D.PalabrasLongitud(longitud);

    cout<<"Palabras de Longitud "<<longitud<<endl;
    for (unsigned int i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    string p;
    cout<<"Dime una palabra: ";
    cin>>p;
    if (D.Esta(p)){
        cout<<"Sí esa palabra existe\n";
    }
    else
        cout<<"Esa palabra no existe\n";
 
}
  
  
  
  