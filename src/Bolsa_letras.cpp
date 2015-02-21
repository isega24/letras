/**
  * @file Bolsa_letras.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include "Bolsa_letras.h"

BolsaLetras::BolsaLetras(BolsaLetras const & otra_bolsa){
    this->bolsa = otra_bolsa.bolsa;
}

void BolsaLetras::aniade_letra(Letra const & letra){
    this->bolsa.push_back(letra);
}

bool BolsaLetras::pertenece(char letra)const{
    /**
      * Inicializamos el bool \e esta a \e false
      * Recorremos con un iterador la lista
      *    Si la letra en la posición recorrida coincide con la letra pasada como argumento
      *    el bool \e esta pasa a ser verdadero
      */
    bool esta = false;
    for(list<Letra>::const_iterator it = bolsa.begin(); !esta && it != bolsa.end(); ++it){
        if((*it).getletra() == letra){
            esta = true;
        }
    }
    return esta;
}

void BolsaLetras::elimina_letra(char letra){
    /**
      * Este metodo se utiliza para el método de busqueda, para que cuando
      * bajes en el arbol, elimines la letra que ya has usado.
      */
    bool esta = false;
    for(list<Letra>::iterator it = bolsa.begin(); !esta && it != bolsa.end(); ++it){
        if((*it).getletra() == letra){
            esta = true;
            bolsa.erase(it);
        }
    }
}

BolsaLetras BolsaLetras::operator=(BolsaLetras const & otra_bolsa){
        this->bolsa = otra_bolsa.bolsa;
        return *this;
}