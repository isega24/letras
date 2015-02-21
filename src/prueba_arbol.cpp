/**
  * @file prueba_arbol.cpp
  * @author Iván Sevillano García y Elena Romero Contreras
  * @date Enero 2015
  */

#include <iostream>
#include <ArbolGeneral.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ArbolGeneral<char> arbol1,arbol2,arbol3,arbol4,arbol5;
    cin >> arbol1;
    cin >> arbol2;
    

    arbol1.asignar_subarbol(arbol2,(arbol1.raiz())->izquierda);
    cout << "Resultado de asignar el arbol2 al hijo mas a la izquierda:"<<arbol1<<endl;
    arbol1.podar_hijomasizquierda(arbol1.raiz(),arbol3);
    cout << "Tras la poda del hijo mas a la izquierda:"<< arbol1 << endl;
    cout << "Rama podadad:" <<arbol3<<endl;
    arbol1 = arbol2;
    cout << "Arboles igualados:" << endl;
    cout << arbol1 << endl << arbol2 << endl;
    ArbolGeneral<char>::Nodo aux = arbol1.raiz();
    aux = aux->izquierda;
    arbol1.podar_hermanoderecha(aux,arbol4);
    cout << "Arbol sin el del medio:" << arbol1 << endl;
    arbol1.insertar_hermanoderecha(aux,arbol4);
    cout << "Con el:" << arbol1 << endl;

    arbol1.insertar_hijomasizquierda(arbol1.raiz(),arbol2);

    cout << "Insertando a la izquierda de la raiz:" << arbol1<<endl;

    arbol1.podar_hijomasizquierda(arbol1.raiz(),arbol2);
    cout << "Quitandoselo:"<< arbol1 << endl;

    if(arbol4 != arbol1){
        cout << arbol4 << "!=" << arbol1 << endl;
    }

    arbol1 = arbol2;
    if(arbol1 == arbol2){
        cout << "El operador de igualdad funciona" << endl;
    }


    ArbolGeneral<char>::iter_preorden iter1;
    ArbolGeneral<char>::const_iter_preorden iter2;

    cout << endl << "Primer iterador:" << endl;
    for(iter1 = arbol1.begin(); iter1 != arbol1.end(); ++iter1){
        cout << *iter1 << " nivel->";
        cout << iter1.getlevel() << endl;
    }
    cout << "Segundo iterador:" << endl;
    for(iter2 = arbol1.begin(); iter2 != arbol1.end(); ++iter2){
        cout << *iter2 << " nivel->";
        cout << iter2.getlevel() << endl;
    }
    return 0;
}