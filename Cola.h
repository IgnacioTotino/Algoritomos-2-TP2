#ifndef NODO_H_
#define NODO_H_

#include "Nodo.h"
#include<iostream>
#include<string>


template<class Tipo> class Cola {

private:

    Nodo<Tipo>* frente;

    Nodo<Tipo>* fondo;

public:


    Cola();
    /*
    PRE:  ....
    POST: Se crea una instancia de COla vac�a y lista para ser usada.        
    */

    bool estaVacia();
    /*
    PRE: ...
    POST: Devuelve 'true' si la Cola no tiene ning�n elemento. Caso contrario, devuelve 'false'.           
    */

    void acolar(Tipo elemento);
    /*
    PRE: ...
    POST: Agrega 'elemento' al fondo de la Cola.
    */

    Tipo desacolar();
    /*
    PRE: La Cola no est� vac�a.
    POST: Remueve el frente de la Cola y lo devuelve.
    */ 

    Tipo obtenerFrente();
    /*
    PRE: La Cola no est� vac�a.
    POST: Devuelve el frente de la Cola.
    */

    void imprimir();
    /*
    PRE: ...
    POST: Imprime por pantalla la Cola.
    */

    ~Cola();
    /*
    PRE: ...
    POST: Remueve todos los elementos y libera los recursos tomados por la estructura de datos.
    */
};

template<class Tipo>
Cola<Tipo>::Cola() {

    this->frente = NULL;
    this->fondo = NULL;
}

template<class Tipo>
bool Cola<Tipo>::estaVacia() {

    return (this->frente == NULL);
}

template<class Tipo>
void Cola<Tipo>::acolar(Tipo elemento) {

    Nodo<Tipo>* nuevoFondo = new Nodo<Tipo>(elemento);

    if (this->estaVacia()) {
        this->frente = nuevoFondo;

    }
    else {
        this->fondo->setearProximo(nuevoFondo);
    }

    this->fondo = nuevoFondo;
}

template<class Tipo>
Tipo Cola<Tipo>::desacolar() {

    if (this->estaVacia()) {
        throw std::string("No se puede desacolar, la cola est� vac�a.");
    }

    // remueve el frente de la estructura 
    Nodo<Tipo>* frenteAnterior = this->frente;

    this->frente = frenteAnterior->proximo();

    if (this->frente == NULL) {
        this->fondo = NULL;
    }

    // devuelve el elemento y libera los recursos asociados 
    Tipo elemento = frenteAnterior->dato();
    delete frenteAnterior;

    return elemento;
}

template<class Tipo>
Tipo Cola<Tipo>::obtenerFrente() {

    if (this->estaVacia()) {
        throw std::string("No se puede obtener el frente, la cola est� vac�a.");
    }

    Tipo elemento = this->frente->dato();

    return elemento;
}

template<class Tipo>
Cola<Tipo>::~Cola() {

    while (!this->estaVacia()) {

        this->desacolar();
    }
}

template<class Tipo>
void Cola<Tipo>::imprimir() {
    Nodo<Tipo>* aux = frente;

    while (aux) {

        std::cout << aux->dato();

        if (aux->prox()) {

            std::cout << " -> ";
        }

        aux = aux->prox();
    }

    std::cout << std::endl;
}

#endif