/**
  * @file Conjunto_letras.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Conjunto_letras.h"
using namespace std;


Letra ConjuntoLetras::GetLetraAleatoria(){
    /**Si el conjunto no es vacío,
      *     Obtenemos letras aleatorias del vector de letras
      *Si es vacío
      *     Devolvemos una letra vacía
      */

    if(this->conjunto.size() != 0){
        int i = rand() % this->conjunto.size();
        return conjunto[i];
    }
    else{
        return Letra('0',0,0);
    }
}

int ConjuntoLetras::obtener_puntuacion(char letra){
    /**
      * Recorre el vector conjunto de letras
      *     Cuando el elemento en la posición \e i de conjunto coincidde con la letra buscada
      *     Devuelve la puntuación asignada a dicha letra
      */

    for(unsigned int i = 0; i < conjunto.size(); i++ ){
        if(conjunto[i].getletra() == letra){
            return conjunto[i].getpuntuacion();
        }
    }
    return 0;
}

vector<Letra> ConjuntoLetras::GetLetras() const{
    vector<Letra> vect;
    unsigned int j = 1;
    for(unsigned int i = 0; i < this->conjunto.size(); i++){
        if( j < this->conjunto.size()){
            if( conjunto[i].getletra() != conjunto[j].getletra()){
                vect.push_back(conjunto[i]);
            }
            j++;
        }
    }
    if(vect[vect.size()-1].getletra() != conjunto[conjunto.size()-1].getletra()){
        vect.push_back(conjunto[conjunto.size()-1]);
    }
    return vect;
}

int ConjuntoLetras::obtener_puntuacion(string palabra){
    /**
      * Inicializa la puntuación a 0
      * Recorre el string \e palabra
      *     Suma la puntuación de cada letra
      */
    int puntuacion = 0;

    for(unsigned int i = 0; i < palabra.size(); i++){
        puntuacion += obtener_puntuacion(palabra[i]);
    }

    return puntuacion;
}


istream & operator>>(istream & is, ConjuntoLetras &conjunto){
    /**
      * Obtenemos una línea del fichero
      * Mientras no lleguemos a fin de archivo,
      *     Creamos letra con los parámetros introducidos
      *     La añadimos al vector conjunto del conjunto pasado como argumento
      */

    int veces, puntuacion;
    char letra;
    string bus;
    getline(is,bus);

    while(!is.eof()){
        is >> letra;
        is >> veces;
        is >> puntuacion;
        Letra caracter(letra,veces,puntuacion);
        for(int i = 0; i < veces; i++){
            conjunto.aniade(caracter); 
        }
    }

    return is;
}
ostream & operator<<(ostream & os, ConjuntoLetras const &conjunto){
    /**
      * Esta sobrecarga se usa para comprobar que funciona conjunto letras.
      * En ella, se recorre cada letra, y se deja atrasado un iterador, para comprobar que no
      * repetimos letras al imprimirlas.
      *     Entonces para cada letra, si no está repetida(la anterior es distinta) la imprimimos.
      */ 
    vector<Letra>::const_iterator iter = conjunto.conjunto.begin();
    for(vector<Letra>::const_iterator it = conjunto.conjunto.begin(); it != conjunto.conjunto.end(); ){
        ++it;
        if((*it).getletra() != (*iter).getletra()){
            os << (*iter).getletra() << '\t'<< (*iter).getpuntuacion() << endl;
        }
        ++iter;
    }
    return os;
}

