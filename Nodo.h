
template <class TipoNodo>
class Nodo {

private:

    TipoNodo datoNodo;
    Nodo<TipoNodo>* siguiente;

public:

    Nodo(TipoNodo info, Nodo<TipoNodo>* next = NULL);
    //PRE: ...
    //POST: El Nodo es creado con sus valores predeterminados o los pasados por par�metros
    
    TipoNodo dato();
    //PRE: El Nodo tiene un tipo de dato v�lido.
    //POST: El Nodo se mantiene igual, ya que se pasa una copia del dato.

    Nodo<TipoNodo>* proximo();
    //PRE: ...
    //POST: El Nodo actual permanece inalterado.
   
    void setearDato(TipoNodo datoNuevo);
    //PRE: ...
    //POST: Se modifica el dato del Nodo.
  
    void setearProximo(Nodo<TipoNodo>* nodoSig);
    //PRE: ... 
    //POST: Modifica el Nodo siguiente al actual.
};


// ...  DEFINICIONES  ...

template <class TipoNodo>
Nodo<TipoNodo>::Nodo(TipoNodo informacion, Nodo<TipoNodo>* siguiente) {

    this->datoNodo = informacion;
    this->siguiente = siguiente;
}

template <class TipoNodo>
TipoNodo Nodo<TipoNodo>::dato() {

    return this->datoNodo;
}

template <class TipoNodo>
Nodo<TipoNodo>* Nodo<TipoNodo>::proximo() {

    return this->siguiente;
}

template <class TipoNodo>
void Nodo<TipoNodo>::setearDato(TipoNodo nuevoDato) {

    this->datoNodo = nuevoDato;
}

template <class TipoNodo>
void Nodo<TipoNodo>::setearProximo(Nodo<TipoNodo>* nodoSiguiente) {

    this->siguiente = nodoSiguiente;
}