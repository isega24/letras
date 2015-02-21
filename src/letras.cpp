/**
  * @file letras.cpp
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

vector<string>::iterator encuentra(vector<string>::iterator inicio,vector<string>::iterator final,string palabra){
    bool esta;
    for(vector<string>::iterator iter = inicio; iter != final;iter++){
        esta = true;
        for(unsigned int i = 0; i < (*iter).size() &&  (*iter).size() == palabra.size() && esta; i++){
            if((*iter)[i] != palabra[i]){
                esta = false;
            }

        }
        if(esta && (*iter).size() == palabra.size()){
            return iter;
        }
    }
    return final;
}

int main(int argc, char const *argv[]){

    if(argc != 5){
        cout << "Los parámetros son:"<<endl;
        cout << "\t1.Nombre del fichero diccionario." << endl;
        cout << "\t2.Nombre del fichero con las letras." << endl;
        cout << "\t3.Numero de letras a generar." << endl;
        cout << "\t4.Modalidad de juego(L=Longitud,P=Puntuacion)." << endl;
        return -1;
    }

    ifstream fdiccionario (argv[1]);
    ifstream fconjunto_letras(argv[2]);
    Diccionario diccionario;
    ConjuntoLetras conjunto;

    fdiccionario >> diccionario;    
    fconjunto_letras >> conjunto;

    BolsaLetras bolsa;
    Letra letra;
    vector<string> soluciones;
    char seguir;
    srand(time(NULL));      //Esto se hace para generar letras aleatorias de conjunto letras.

    do{
        if(argv[4][0] == 'L'){
            
            cout<< "Escogio el modo de juego de Longitud\n";
            
            cout << "Las letras son:\t";
            for(int i = 0; i < atoi(argv[3]);i++){
                letra = conjunto.GetLetraAleatoria();
                cout << letra.getletra()<<"\t";
                bolsa.aniade_letra(letra);
            }
            soluciones = diccionario.encuentra_palabras(bolsa);
            cout << "\nDime tu solucion:";
            string solucion;
            cin >> solucion;

            
            if(encuentra(soluciones.begin(),soluciones.end(),solucion) == soluciones.end()){
                cout << "\nLo siento, no es una solución valida"<<endl;
            }
            else{
                cout << endl <<solucion << "\tLongitud: "<< soluciones.size()<<endl;
            }

            cout << "\nMis soluciones son:\n";

            for(vector<string>::const_iterator iter = soluciones.begin(); iter != soluciones.end();++iter){
                cout << *iter << "\tLongitud:"<< (*iter).size() <<endl;
            }


            solucion = soluciones[0];
            for(unsigned int i = 0; i < soluciones.size(); i++){
                if(soluciones[i].size() > solucion.size()){
                    solucion = soluciones[i];
                }
            }


            cout <<"\nLa solucion mas larga es: " << solucion << endl;
            bolsa = BolsaLetras();
            cout << "¿Quieres seguir jugando?(S/n)";
            cin >> seguir;
            cout << endl;
        }
        else if(argv[4][0] == 'P'){
        
            cout<< "Escogio el modo de juego de Puntuacion\n";
            cout << "Puntuaciones:\n" << conjunto << endl;
            cout << "Las letras son:\t";
            for(int i = 0; i < atoi(argv[3]);i++){
                letra = conjunto.GetLetraAleatoria();
                cout << letra.getletra()<<"\t";
                bolsa.aniade_letra(letra);
            }
            cout << "\nDime tu solucion:";
            string solucion;
            cin >> solucion;
            soluciones = diccionario.encuentra_palabras(bolsa);
    
            if(encuentra(soluciones.begin(),soluciones.end(),solucion) == soluciones.end()){
                cout << "\nLo siento, no es una solución valida"<<endl;
            }
            else{
                cout << endl << solucion << "\tPuntuacion:"<< conjunto.obtener_puntuacion(solucion)<<endl;
            }
    
            cout << "\nMis soluciones son:\n";
    
            for(vector<string>::const_iterator iter = soluciones.begin(); iter != soluciones.end();++iter){
                cout << *iter << "\tPuntuacion:"<<conjunto.obtener_puntuacion(*iter) <<endl;
            }
    
            for(unsigned int i = 0; i < soluciones.size(); i++){
                if(conjunto.obtener_puntuacion(soluciones[i]) > conjunto.obtener_puntuacion(solucion)){
                    solucion = soluciones[i];
                }
            }
    
            
            cout <<"\nLa mejor solucion en cuanto a puntuacion es: "<< solucion  << "\tPuntuacion:"<< conjunto.obtener_puntuacion(solucion) << endl;
            bolsa = BolsaLetras();
            cout << "¿Quieres seguir jugando?(S/n)";
            cin >> seguir;
        }
        
        
        else{
            cout << "No escogio ningún modo de juego."<<endl;
        }
    }while((seguir == 'S' || seguir == 's')&&(argv[4][0] == 'L'||argv[4][0] == 'P'));


    return 0;
}