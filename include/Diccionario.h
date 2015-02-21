#ifndef __Diccionario_h__
#define __Diccionario_h__

/**
  * @file Diccionario.h
  */

using namespace std;

#include <vector>
#include <string>
#include "ArbolGeneral.h"
#include "Bolsa_letras.h"


struct info{
    char c; ///<< caracter que se almacena en un nodo
    bool final; ///< nos indica si es final o no de palabra
    info(){
        c='\0';
        final=false;
    }
    info(char car, bool f):c(car),final(f){}
};

/**
   @brief T.D.A. Diccionario

   \b Definición:
   Una instancia \e d del tipo de dato abstracto Diccionario está constituido
   por un árbol sobre el struct \e info que almacena caracteres que forman palabras 
   
   Para poder usar el tipo de dato Diccionario se debe incluir el fichero
   
   <tt>\#include Diccionario.h</tt>
   
   @author Iván Sevillano García y Elena Romero Contreras
   @date Enero 2015
*/

class Diccionario{
private:

    /**
      * @brief Arbol 
      * En este campo se almacena el árbol con los datos
      */
    ArbolGeneral<info> datos;

    /**
      * @brief Encuentra las palabras que se pueden construir con las letras pasadas en la bolsa
      * @param bolsa Es la bolsa de letras que contiene los caracteres para formar palabras
      * @param nodo Nodo a partir del cual iniciaremos la búsqueda
      * @return vector de string con las palabras encontradas
      */
    vector<string> encuentra_palabras(BolsaLetras bolsa, ArbolGeneral<info>::Nodo nodo);

public:

    /**
      * @brief Constructor por defecto
      * Inicializa un diccionario vacío
      * La operación se realiza en tiempo O(1)
      */
    Diccionario(){this->datos = ArbolGeneral<info>(info('0',false));};

    /**
      * @brief Obtiene el tamaño del diccionario
      * @return Devuelve el numero de palabras en el diccionario
      */
    int size() const ;

    /**
      * @brief Añade al árbol de datos de \e palabra en orden.
      * @param palabra Es un string con la palabra que queremos añadir al árbol
      */
    void aniade_palabra(string palabra);

    /**
      * @brief Obtiene todas las palabras en el diccionario de un longitud dada
      * @param longitud: la longitud de las palabras de salida
      * @return un vector con las palabras de longitud especifica en el parametro de entrada
      */
    vector<string> PalabrasLongitud(int longitud)const;

    /**
      * @brief Indica si una palabra está en el diccionario o no
      * @param palabra: la palabra que se quiere buscar
      * @return true si la palabra esta en el diccionario. False en caso contrario
      */
    bool Esta(string palabra)const;

    /**
      * @brief Encuentra las palabras que se pueden construir con las letras pasadas en la bolsa
      * @param bolsa Es la bolsa de letras que contiene los caracteres para formar palabras
      * @return vector de string con las palabras encontradas
      */
    vector<string> encuentra_palabras(BolsaLetras bolsa){return encuentra_palabras(bolsa,this->datos.raiz());}

    /**
      * @brief Cuenta el número de apariciones de cada letra en el diccionario
      * @return Devuelve un vector con el número de apariciones de cada letra
      */
    vector<int> numero_apariciones();

    /**
      * @brief Obtiene el número total de letras que aparecen en el diccionario
      */
    int total_letras();

    /**
      * @brief Lee de un flujo de entrada un diccionario
      * @param is:flujo de entrada
      * @param D: el objeto donde se realiza la lectura.
      * @return el flujo de entrada
      */
    friend istream & operator>>(istream & is,Diccionario &D);

    /**
      * @brief Escribe en un flujo de salida un diccionario
      * @param os:flujo de salida
      * @param D: el objeto diccionario que se escribe
      * @return el flujo de salida
      */
    friend ostream & operator<<(ostream & os, const Diccionario &D); 

    /**
      * @brief TDA. Iterador del Diccionario
      */
    class iterator{
    private:
        ArbolGeneral<info>::const_iter_preorden it;
        string cad; //mantiene los caracteres desde el nivel 1 hasta donde se encuentra it.
    public:

        /*
         * @brief Constructor por defecto
         */
        iterator (){}

        /*
         * @brief Devuelve el contenido de \e cad
         * @return Devuelve la cadena de caracteres desde el nivel 1 hasta donde se encuentra it
         */
        string operator *()const{
        	return cad;
        }

        /**
          * @brief Obtiene un iterador a la siguiente palabra del diccionario
          * 
          */
        iterator & operator ++();

        /**
          * @brief Compara dos iteradores
          * @param i: iterador con el  que se compara
          * @return true si los dos iteradores son iguales 
          */
        bool operator ==(const iterator &i)const{
        	return (this->it == i.it);
        }

        /**
          * @brief Compara dos iteradores
          * @param i: iterador con el  que se compara
          * @return true si los dos iteradores son diferentes 
          */
        bool operator !=(const iterator &i)const{
        	return (this->it != i.it);
        }

        /*
         * @brief Obtiene la longitud de la cadena de caracteres recorrida
         * @param devuelve el nivel en el que se encuentra el iterador
         */
        int getlongitud()const{
            return this->it.getlevel();
        }

        friend class Diccionario;
    };

    /**
      * @brief Inicializa iterador
      */
    iterator begin()const{
        iterator it;
        it.it = datos.begin();
        it.cad.clear();
        return it;
    }

    /**
      * @brief Inicializa iterador 
      */
    iterator end()const{
        iterator it;
        it.it = datos.end();
        return it;
    }

     
};

#endif
