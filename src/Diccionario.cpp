/**
  * @file Diccionario.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include "Diccionario.h"

int Diccionario::size() const{

    Diccionario::iterator iter;
    int i = 0;
    for(iter = begin(); iter != end(); ++iter){
        i++;
    }

   return i;
}

void Diccionario::aniade_palabra(string cadena){
    ArbolGeneral<info>::Nodo nodo = this->datos.raiz();
    ArbolGeneral<info> rama;
    if(this->datos.hijomasizquierda(nodo) == NULL){
        rama = ArbolGeneral<info>(info(cadena[0],cadena.size() == 1));
        this->datos.insertar_hijomasizquierda(nodo,rama);
    }
    nodo = this->datos.hijomasizquierda(nodo);


    for(unsigned int i = 0; i  < cadena.size(); i++){
        while(this->datos.etiqueta(nodo).c < cadena.at(i) && this->datos.hermanoderecha(nodo)!=NULL){
            nodo = this->datos.hermanoderecha(nodo);
        }

        if(this->datos.etiqueta(nodo).c != cadena.at(i)){
            bool perfecto = (i==cadena.size()-1);
            info inf = info(cadena.at(i),perfecto);
            rama = ArbolGeneral<info>(inf);
            this->datos.insertar_hermanoderecha(nodo,rama);
            nodo = this->datos.hermanoderecha(nodo);
        }
        if(this->datos.hijomasizquierda(nodo)== NULL&& cadena.size() > i + 1){
            rama = ArbolGeneral<info>(info(cadena.at(i+1),i==cadena.size()-2));
            this->datos.insertar_hijomasizquierda(nodo,rama);
        }
        nodo = this->datos.hijomasizquierda(nodo);
    }
}

vector<string> Diccionario::PalabrasLongitud(int longitud)const{
   vector<string> palabras_longitud;
   Diccionario::iterator iterador;

    for(iterador = begin(); iterador != end(); ++iterador){

        if((iterador.getlongitud() == longitud)){
            palabras_longitud.push_back(*iterador);
        }
    }   
   return palabras_longitud;
}

bool Diccionario::Esta(string palabra)const{
   bool esta = true;
   unsigned int posicion = 0;
   ArbolGeneral<info>::Nodo nodo = datos.raiz();
   nodo = datos.hijomasizquierda(nodo);

    while(posicion < palabra.size() && esta){
        if(datos.etiqueta(nodo).c != palabra.at(posicion)){
            nodo = datos.hermanoderecha(nodo);
            if(nodo == NULL){
                esta = false;
            }
        }
        else{
            nodo = datos.hijomasizquierda(nodo);
            posicion++;
        }
    }
    if( nodo == NULL){
        return esta;
    }
    else{
        return this->datos.etiqueta(nodo).final && esta;
    }

   
}

vector<int> Diccionario::numero_apariciones(){
    vector<int> numero_apariciones;

    for(unsigned int i = 'a'; i <= 'z';i++){
        numero_apariciones.push_back(0);
    }
    Diccionario::iterator iterador;

     for(iterador = begin(); iterador != end(); ++iterador){
        for(unsigned int i =0; i < (*iterador).size(); i++){
            if((*iterador)[i] >= 'a' && (*iterador)[i] <= 'z'){
                numero_apariciones[(*iterador)[i] - 'a']++;
            }
        }
    }   

    return numero_apariciones;
}

int Diccionario::total_letras(){
    vector<int> numero_apariciones = this->numero_apariciones();
    int tamanio = numero_apariciones.size();
    int total;

    for(int i=0; i< tamanio; i++){
        total = total + numero_apariciones[i];
    }
    return total;
}

//!!!!!!!!!!!!!!!!!!
istream & operator>>(istream & is,Diccionario &D){
    ArbolGeneral<info>::Nodo inicio = D.datos.raiz(),aux;
    string cadena;

    while(!is.eof()){
        getline(is,cadena);
        D.aniade_palabra(cadena);

    }

    return is;
}

ostream & operator<<(ostream & os, const Diccionario &D){

    Diccionario::iterator iterador;

    for(iterador = D.begin(); iterador != D.end(); ++iterador){
        os << *iterador << endl;
    }   

    return os;
}

Diccionario::iterator & Diccionario::iterator::operator++(){ 
    int level = this->it.getlevel();
    do{
        ++(this->it);
        if(it.getlevel() > 0){
            if(it.getlevel() <= level){
                cad = cad.substr(0,it.getlevel()-1);
                cad.push_back((*it).c);
            }
            else{
                cad.push_back((*it).c);
            }
            level = this->it.getlevel();
        }
        else{
            break;break;
        }
    }while(!(*it).final);
    return *this;
}

vector<string> Diccionario::encuentra_palabras(BolsaLetras bolsa, ArbolGeneral<info>::Nodo nodo){

    /**
    * Este es el algorítmo para buscar.
    */

    vector<string> palabras, palabras_aux;
    string palabra_aux;
    BolsaLetras bolsa_aux;
    ArbolGeneral<info>::Nodo nodo_aux = this->datos.hijomasizquierda(nodo),nodo_aux2;

    while(nodo_aux != NULL){
        if(bolsa.pertenece(this->datos.etiqueta(nodo_aux).c)){
            bolsa_aux = bolsa;
            bolsa_aux.elimina_letra(this->datos.etiqueta(nodo_aux).c);
            palabras_aux = encuentra_palabras(bolsa_aux,nodo_aux);
            palabras.insert(palabras.end(),palabras_aux.begin(),palabras_aux.end());
            if(this->datos.etiqueta(nodo_aux).final){
                nodo_aux2 = nodo_aux;
                palabra_aux.clear();
                while(nodo_aux2 != this->datos.raiz()){
                    palabra_aux.insert(0,1,this->datos.etiqueta(nodo_aux2).c);
                    nodo_aux2 = this->datos.padre(nodo_aux2);
                }
                palabras.push_back(palabra_aux);
            }
        }
        nodo_aux = this->datos.hermanoderecha(nodo_aux);
    }
    return palabras;
}