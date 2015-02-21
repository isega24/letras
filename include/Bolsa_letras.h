#ifndef __Bolsa_letras_h__
#define __Bolsa_letras_h__

/**
  * @file Bolsa_letras.h
  */
  
#include <list>
#include "Conjunto_letras.h"

using namespace std;

/**
   @brief T.D.A. BolsaLetras

    \b Definición:
   Una instancia \e b del tipo de dato abstracto BolsaLetras es una lista de letras
   correspondientes a letras de un conjunto de letras, seleccionadas aleatoriamente.
   
   Para poder usar el tipo de dato BolsaLetras se debe incluir el fichero
   
   <tt>\#include Bolsa_letras.h</tt>


   @author Iván Sevillano García y Elena Romero Contreras
   @date Enero 2015
*/

class BolsaLetras{
/**
  * @page repConjunto Rep del TDA BolsaLetras
  *
  * @section invConjunto Invariante de representación
  *
  * Sea \e B una BolsaLetras:
  *     - si \e B es vacía, la lista de \e Letras tiene 0 elementos
  *     - Si \e B no es vacía, cada elemento de la lista es un objeto Letra.
  */
private:

    /**
      * @brief Lista de letras 
      */
    list<Letra> bolsa;

public:

    /**
      * @brief Constructor por defecto.
      */
    BolsaLetras(){};

    /**
      * @brief Constructor de copia.
      * @param otra_bolsa Bolsa a copiar
      *
      * Construye la bolsa duplicando el contenido de \e otra_bolsa
      * en la bolsa receptora.
      */

    BolsaLetras(BolsaLetras const & otra_bolsa);

    /**
      * @brief Añade una letra a la lista de letras
      * @param letra Referencia a la letra que añadiremos
      */
    void aniade_letra(Letra const & letra);

    /**
      * @brief Comprueba si una letra pertenece a la bolsa
      * @param letra Es la letra a comprobar
      * @return Devuelve \e true cuando la letra pasada pertenezca a la bolsa.
      */
    bool pertenece(char letra)const;

    /**
      * @brief  Elimina una letra
      * @param letra Es la letra que eliminaremos
      * En caso de haber varias, elimina solo una instancia.
      */
    void elimina_letra(char letra);

    /**
      * @brief Operador de asignación.
      * @param otra_bolsa Es la bolsa que queremos asignar
      * @return Devuelve una referencia a nuestra bolsa,
        ya con los datos de la bolsa pasada como argumento
      */
    BolsaLetras operator=(BolsaLetras const & otra_bolsa);

};

#endif