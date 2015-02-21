/**
  * @file Cantidad_letras.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include "Diccionario.h"
#include "Bolsa_letras.h"
#include "Conjunto_letras.h"

using namespace std;

/*
 * Calcula la frecuencia de aparición de cada letra
 */
double calcula_porcentaje(double cantidad_letra, double cantidad_total){
    return (cantidad_letra/cantidad_total*1.0) * 100;
}


int main(int argc, char const *argv[]){
	
	if(argc != 4){
        cout << "Los parámetros son:"<<endl;
        cout << "\t1.Nombre del fichero diccionario." << endl;
        cout << "\t2.Nombre del fichero con las letras." << endl;
        cout << "\t3.Fichero de salida" << endl;
        return -1;
    }

    ifstream fdiccionario (argv[1]);
    ifstream fconjunto_letras(argv[2]);
    ofstream fsalida(argv[3]);

    Diccionario diccionario;
    ConjuntoLetras conjunto;
    vector<Letra> conjunto_letras;
    int tamanio_conjunto;
    vector<int> numero_apariciones;
    int apariciones;
    int total_letras;

    fdiccionario >> diccionario;    
    fconjunto_letras >> conjunto;

    conjunto_letras = conjunto.GetLetras();
    tamanio_conjunto = conjunto_letras.size();
    numero_apariciones = diccionario.numero_apariciones();
    total_letras = diccionario.total_letras();

    for(int i= 0; i < tamanio_conjunto; i++){
        apariciones = numero_apariciones[conjunto_letras[i].getletra()-'a'];
        fsalida << "Letra: " << conjunto_letras[i].getletra() 
            << "\nNúmero de apariciones: " << apariciones
            << "\nFrecuencia de aparición: " << calcula_porcentaje(apariciones, total_letras)
             << "\nPuntuación: " << conjunto_letras[i].getpuntuacion() << endl << endl;
        if(i < tamanio_conjunto -1){
            fsalida << endl;
        }

    }






}