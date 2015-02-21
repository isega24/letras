/**
    @file ArbolGeneral.cpp
    @author Iván Sevillano García y Elena Romero Contreras
    @date Enero 2015
*/

template <class Tbase>
void ArbolGeneral<Tbase>::destruir(Nodo n){

    /*
    Destruimos todas las ramas del arbol por orden, de izquierda a derecha utilizando el puntero
    del padre como marcador, adelantando el marcador antes de destruir cada nodo.
    */
    if(n != NULL){

        Nodo aux;
        while(n->izquierda != NULL){
            aux = n->izquierda;
            n->izquierda = n->izquierda->derecha;
            destruir(aux);
        }
    }
}
template <class Tbase>
void ArbolGeneral<Tbase>::copiar(Nodo &dest, Nodo orig){

    /*
    (Solo es la copia de lo que cuelga)
    Copiamos la etiqueta del primer nodo. Despues si el puntero que apunta al primer hijo
    y no es NULL, creamos un nodo que colgará de dest a la izquierda para empezar el algoritmo recursivo
    Creamos punteros apuntando cada uno al hijo de orig a la izquierda
    y otro al nuevo nodo creado. Entonces:
        Si hay hijos que copiar:
                Copiamos aux1 en aux2.
                Hacemos que el padre de aux2 sea dest.
                Adelantamos aux1.
                Si aux1 es distinto de NULL, es que hay mas hermanos que copiar, asi que:
                    A la derecha de aux2 crea otro nodo y adelanta aux2.

            Mientras aux1 sea distinto de NULL(No haya mas hermanos).
            Nos aseguramos de que el ultimo hijo apunta a su derecha a NULL.
        Si no hay:
            Asigna NULL a la izquierda de dest.
    */
    Nodo aux1 = orig->izquierda;
    if(aux1 != NULL){
        Nodo aux2 = dest->izquierda = new typename ArbolGeneral<Tbase>::nodo;

      
        do{
            aux2->etiqueta = aux1->etiqueta;
            aux2->padre = dest;
            copiar(aux2,aux1);
            aux1 = aux1->derecha;
            if(aux1 != NULL){
                aux2 = aux2->derecha = new typename ArbolGeneral<Tbase>::nodo;
                
            }
            
        }while(aux1 != NULL);

        aux2->derecha = NULL;
    }
    else{
        dest->izquierda = NULL;
    }
}

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const ArbolGeneral<Tbase>::nodo * n) const{
    /*
    Se inicializa a 1 la suma total(el del nodo actual) y se crea un puntero para señalar el atual.
    Mientras haya hijos que contar:
        A la suma total se le añade lo que se ha contado en ese nodo.
        Se adelanta el puntero auxiliar.
    Se devuelve la suma.
    */
    int suma = 1;
    Nodo aux = n->izquierda;
    while(aux != NULL){
        suma += contar(aux);
        aux = aux->derecha;
    }
    return suma;
}
template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const ArbolGeneral<Tbase>::nodo * n1, const ArbolGeneral<Tbase>::nodo * n2) const{
    /*
    Si las etiquetas del nodo son distintas, devuelve false. Si no:
        Se crean punteros que apunten a la izquierda de los nodos.
        Mientras estos nodos sean distintos de NULL y lo que cuelga de estos sea igual:
            Se comprueba que sean iguales y se adelantan al nodo sigueinte.
        Se devuelve si todos han sido iguales y si ambos han terminado de comprobarse a la vez:
        (No hay mas hermanos que comprobar)
    */
    if(n1->etiqueta != n2->etiqueta){
        return false;
    }
    else{
        bool iguales = true;
        Nodo aux1 = n1->izquierda, aux2 = n2->izquierda;
        while(iguales && aux1 != NULL && aux2 != NULL){
            iguales = this->soniguales(aux1,aux2);
            aux1 = aux1->derecha;
            aux2 = aux2->derecha;

        }
        return iguales && (aux1 == aux2);   //Esto ocurre si ambos son NULL, por lo que los arboles
                                            //terminan a la vez.
    }
}
template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, Nodo nod) const{

    /**
    * Este método da por supuesto que el nodo no es nulo. Imprime la letra n y 
    * la etiqueta del nodo. Despues, mientras tenga hijos, los imprime con esta misma
    * función. Termina imprimiendo una x, que marca que no hay nada más bajo él.
    */
    
    out << 'n' << nod->etiqueta;
    Nodo aux = nod->izquierda;
    while(aux != NULL){
        escribe_arbol(out,aux);
        aux = aux->derecha;
    }
    out << 'x';
    
}
template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, Nodo& nod){ 

    /*
    * Este método dá por supuesto que el primer carácter está leido, esto es, que el nodo no va
    * a ser nulo. El algoritmo hace lo siguiente:
    *       Lee la etiqueta del nodo en el que estamos.
    *       Lee el carácter que dice si tiene o no hijos.
    *       Si es 'n', reservamos espacio para tal hijo y lo 'enganchamos' al padre.
    *       Mientras esta marca sea 'n':
    *           Leemos en el nodo hijo lo que haya bajo el.
    *           Lo 'enganchamos' al padre.
    *           Leemos la siguiente marca, y si no es 'x':
    *               Creamos el siguiente hijo y pasasmos a el para la siguiente lectura.
    * 
    */

    Tbase aux;
    char marca;
    in >> aux;
    nod->etiqueta = aux;
    in >> marca;
    Nodo nodoaux;
    if( marca == 'n'){
        nodoaux = nod->izquierda = new typename ArbolGeneral<Tbase>::nodo;
    }
    while(marca == 'n'){
        lee_arbol(in,nodoaux);
        nodoaux->padre = nod;
        in >> marca;
        nodoaux->derecha = NULL;
        if( marca != 'x'){
            nodoaux = nodoaux->derecha = new typename ArbolGeneral<Tbase>::nodo;
        }
    }
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v){

    this->laraiz = new ArbolGeneral<Tbase>::nodo;
    this->laraiz->padre = NULL;
    this->laraiz->derecha = NULL;
    this->laraiz->etiqueta = (v.raiz())->etiqueta;
    copiar(this->laraiz,v.raiz());
}

template<class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
    this->clear();
}

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v){

    /**
    * Si la raiz no es nula, destruye sus descendientes.
    * En caso de que lo sea, se crea el nodo raiz en el que se va a asignar el arbol en la raiz.
    *
    * Tras esto, se copia el árbol en la raiz.
    */

    if(this->laraiz != NULL){
        destruir(this->laraiz);
    }
    else{

        this->laraiz = new typename ArbolGeneral<Tbase>::nodo;

    }
    this->laraiz->padre = this->laraiz->derecha = NULL;
    this->laraiz->etiqueta = (v.raiz())->etiqueta;
    copiar(this->laraiz,v.raiz());
    return *this;
}

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, Nodo nod){ 

    destruir(nod);

    copiar(nod,orig.raiz());
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){

    dest.clear();
    dest.laraiz = n->izquierda;
    if(dest.laraiz != NULL){
        n->izquierda = n->izquierda->derecha;
        dest.laraiz->derecha = NULL;
        dest.laraiz->padre = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
    dest.clear();
    if( n != NULL){
        if(n->derecha != NULL){
            dest.laraiz = n->derecha;
            n->derecha = n->derecha->derecha;
            dest.laraiz->derecha = NULL;
            dest.laraiz->padre = NULL;
        }
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
    if(n != NULL){
        Nodo aux = n->izquierda;
        n->izquierda = rama.laraiz;
        n->izquierda->padre = n;
        n->izquierda->derecha = aux;
        rama.laraiz = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
        
    if(n != NULL){
        Nodo aux = n->derecha;
        
        n->derecha = rama.laraiz;
        n->derecha->padre = n->padre;
        n->derecha->derecha = aux;
        rama.laraiz = NULL;
    }
}

template<class Tbase>
bool ArbolGeneral<Tbase>::operator == (const ArbolGeneral<Tbase>& v) const{
    if(this->laraiz == NULL){
        if(v.raiz() == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return soniguales(this->laraiz,v.raiz());
    }
}

template<class T> 
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v){

    /**
    * Leemos la marca. Si es no nula, procedemos a crear la raiz. Tras esto, 
    * leemos 
    */

    char marca;
    in >> marca;
    if(marca == 'n'){
        v.clear();
        v.laraiz = new typename ArbolGeneral<T>::nodo;
        v.lee_arbol(in,v.laraiz);
    }
    return in;
}

template<class T>
std::ostream& operator<< (std::ostream& out, const ArbolGeneral<T>& v){
    if(v.laraiz != NULL){
        v.escribe_arbol(out,v.laraiz);
    }
    else{
        out << 'x';
    }
    return out;
}

template<class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden & ArbolGeneral<Tbase>::iter_preorden::operator++(){
    
    if(it == NULL){
        return *this;
    }
    if(it->izquierda !=NULL){
        it = it->izquierda;
        level++;
    }
    else if(it->derecha != NULL){
        it = it->derecha;
    }   
    else{
        while(it->derecha == NULL && it->padre != NULL){
            it = it->padre;
            level--;
        }
        it = it->derecha;
    }

    return *this;
}

template<class Tbase>
typename ArbolGeneral<Tbase>::const_iter_preorden & ArbolGeneral<Tbase>::const_iter_preorden::operator++(){

    if(it == NULL){
        return *this;
    }
    if(it->izquierda !=NULL){
        it = it->izquierda;
        level++;
    }
    else if(it->derecha != NULL){
        it = it->derecha;
    }   
    else{
        while(it->padre != NULL && it->derecha == NULL){
            it = it->padre;
            level--;
        }
        it = it->derecha;
        
    }
    return *this;
}