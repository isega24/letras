#ifndef __Conjunto_letras_h__
#define __Conjunto_letras_h__

/**
  * @file Conjunto_letras.h
  */

#include <vector>
#include <string>

using namespace std;

#define A_MINUS 'a'-'A'

/**
   @brief T.D.A. Letra

    \b Definición:
   Una instancia \e l del tipo de dato abstracto Letra contiene un caracter 
   \e letra, que tendrá asociado un número de veces de aparición  \e veces
   y una puntuación \e puntuacion
   
   Para poder usar el tipo de dato Letra se debe incluir el fichero
   
   <tt>\#include Conjunto_letras.h</tt>
   

   @author Iván Sevillano García y Elena Romero Contreras
   @date Enero 2015
*/

class Letra{
/**
  * @page repConjunto Rep del TDA Letra
  *
  * @section invConjunto Invariante de representación
  *
  * Sea \e L una Letra:
  *     - si \e L es vacía, entonces el número de veces de aparición y la puntuación son 0
  *     - si \e L no es vacía, entonces veces y puntuación son mayores que 0
  
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido \e l de la clase Letra se representa:
  *
  * {letra, veces, puntuacion}
  */
private:

    /**
      * @brief caracter
      * En este campo se almacena el caracter
      */
    char letra;

    /**
      * @brief número de veces
      * En este campo se almacena el número de veces que aparece \e letra
      */
    int veces;

    /**
      * @brief puntuacion
      * En este campo se almacena la puntuación asignada a \e letra
      */
    int puntuacion;

public:

    /**
      * @brief Constructor por defecto.
      * Inicializa una letra vacía, que aparece cero veces y puntuación nula
      * La operación se realiza en O(1)
      */

    Letra(){letra = '\0',veces = puntuacion = 0;};

    /**
      * @brief Constructor de la clase
      * @param letra Caracter que almacena
      * @param veces Numero de veces que aparece letra
      * @param puntuacion Puntuación asignada a dicha letra
      *
      * Inicializa una letra con un determinado número de apariciones y puntuación
      * La operación se realiza en O(1)
      */
    Letra(char letra,int veces,int puntuacion){
        this->letra = letra + A_MINUS;
        this->veces = veces;
        this->puntuacion = puntuacion;
    }

    /**
      * @brief Obtiene el caracter de la letra.
      * @return Devuelve el caracter
      * La operación se realiza en O(1)
      */
    char getletra()const{return this->letra;}

    /**
      * @brief Obtiene el dato miembro \e veces
      * @return Devuelve las veces que puede aparecer la letra
      * La operación se realiza en O(1)
      */
    int getveces()const{return this->veces;}

    /**
      * @brief Obtiene el dato miembro \e puntuacion
      * @return Puntuación de la letra
      * La operación se realiza en O(1)
      */
    int getpuntuacion()const{return this->puntuacion;}

    /**
      * @brief Operador de comparación (igualdad)
      * @param letra Letra con la que se quiere comparar
      * @return Devuelve \e true si el caracter de la letra receptora coincide
      * La operación se realiza en O(1)
      */
    bool operator==(Letra letra)const{
        return this->getletra() == letra.getletra();
    }


};

/**
   @brief T.D.A. ConjuntoLetras

   \b Definición:
   Una instancia \e c del tipo de dato abstracto ConjuntoLetras contiene
   un vector de objetos de la clase \e Letra.

   Este tipo de dato asemeja el funcionamiento de una bolsa, en la que hemos metido
   varias letras, no tiene porque ser no repetidas, y de la que aleatoriamente sacaremos
   una de ellas para observarla, anotarla y devolverla al conjunto. Así conseguimos que
   no varía la frecuencia de aparición de las letras.
   
   Para poder usar el tipo de dato ConjuntoLetras se debe incluir el fichero
   
   <tt>\#include Conjunto_letras.h</tt>


   @author Iván Sevillano García y Elena Romero Contreras
   @date Enero 2015
*/

class ConjuntoLetras{
/**
  * @page repConjunto Rep del TDA ConjuntoLetras
  *
  * @section invConjunto Invariante de representación
  *
  * Sea \e C un ConjuntoLetras:
  *     - si \e C es vacío, el vector de Letras \e conjunto tiene 0 elementos
  *     - si \e C no es vacío, cada elemento del vector conjunto es un objeto de la
  *       clase Letra
  *
  * @section faConjunto Función de abstracción

  * Un objeto válido \e B del tipo de dato abstracto ConjuntoLetras se representa:
  *
  *   {{letra_1,...,letra_1},...,{letra_n,...,letra_n}}
  * donde n es el número de letras diferentes que aparecen 
  */

private:
    
    /**
      * @brief Conjunto de letras repetidas
      * En este campo se almacena un vector con las letras del conjunto
      */
    vector<Letra> conjunto;

    /**
      * @brief Añade una letra al conjunto de letras
      * @param letra Es la letra a añadir al conjunto
      * La operación se realiza en O(1)
      */
    void aniade(Letra letra){conjunto.push_back(letra);}

    /**
      * @brief Obtiene la puntuación de una letra
      * @param letra Es el caracter que representa a letra
      * @return Devuelve la puntuación asignada a la letra pasada como argumento
      */
    int obtener_puntuacion(char letra);

public:
    
    /**
      * @brief Constructor por defecto
      * Se inicializa un conjunto de letras vacío
      * La operación se realiza en O(1)
      */
    ConjuntoLetras(){};

    /**
      * @brief Obtiene el conjunto de letras
      * @return Devuelve el vector que almacena el conjunto de letras
      */
    vector<Letra> GetLetras() const;

    /**
      * @brief Obtiene una letra aleatoria
      * @return Devuelve una letra de la bolsa de letras
      */
    Letra GetLetraAleatoria();

    /**
      * @brief Obtiene la puntuacion de una palabra.
      * @param palabra String que almacena la palabra 
      * @return puntuacion Devuelve la putuacion total de la palabra pasada como argumento
      */
    int obtener_puntuacion(string palabra);

    /** @brief Operador de extracción de flujo
      * @param is Stream de entrada
      * @param conjunto Conjunto que leer
      * @return Referencia al stream de entrada
      *
      * Lee de \e is un archivo y lo almacena en \e conjunto.
      */
    friend istream & operator>>(istream & is, ConjuntoLetras & conjunto);
    /**
      * @brief Operador de inserción en flujo
      * @param out Stream de salida
      * @param conjutno Conjunto que escribir
      * @return Referencia al stream de salida
      */
    friend ostream & operator<<(ostream & os, ConjuntoLetras const & conjunto);
    
};

#endif