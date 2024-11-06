#include <iostream>
using namespace std;

int criterio = 1;

struct NodoPila {
    int info;
    NodoPila* sgte;
};

struct NodoCola {
    int info;
    NodoCola* sgte;
};

struct NodoLista {
    int info;
    NodoLista* sgte;
};

void agregarPila(NodoPila*&, int);
void sacarPila(NodoPila*&, int&);
void insertarOrdenado(NodoLista*&, int);
void insertarCola(NodoCola*&, NodoCola*&, int);
void sacarCola(NodoCola*&, NodoCola*&, int&);
void unirPilaCola(NodoPila*&, NodoCola*&, NodoCola*&, NodoLista*&);
void mostrarLista(NodoLista*);

int main() {
    NodoPila* pila = NULL;
    NodoCola* frente = NULL;
    NodoCola* fin = NULL;
    NodoLista* lista = NULL;

    agregarPila(pila, 34);
    agregarPila(pila, 33);
    agregarPila(pila, 354);
    agregarPila(pila, 366);

    insertarCola(frente, fin, 7);
    insertarCola(frente, fin, 75);
    insertarCola(frente, fin, 7232);
    insertarCola(frente, fin, 7442);

    unirPilaCola(pila, frente, fin, lista);
    mostrarLista(lista);

    return 0;
}

void unirPilaCola(NodoPila*& pila, NodoCola*& frente, NodoCola*& fin, NodoLista*& lista) {
    int info;

    // Procesa y vacía la pila en la lista ordenada
    while (pila != NULL) {
        sacarPila(pila, info);
        insertarOrdenado(lista, info);
    }

    // Procesa y vacía la cola en la lista ordenada
    while (frente != NULL) {
        sacarCola(frente, fin, info);
        insertarOrdenado(lista, info);
    }
}

void agregarPila(NodoPila*& pila, int n) {
    NodoPila* nuevo_nodo = new NodoPila();
    nuevo_nodo->info = n;
    nuevo_nodo->sgte = pila;
    pila = nuevo_nodo;
    cout << "\nElemento " << n << " agregado exitosamente a la pila" << endl;
}

void sacarPila(NodoPila*& pila, int& n) {
    NodoPila* aux = pila;
    n = aux->info;
    pila = aux->sgte;
    delete aux;
}

void insertarCola(NodoCola*& frente, NodoCola*& fin, int n) {
    NodoCola* nuevo_nodo = new NodoCola();
    nuevo_nodo->info = n;
    nuevo_nodo->sgte = NULL;
    if (frente == NULL) {
        frente = nuevo_nodo;
    } else {
        fin->sgte = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\nElemento " << n << " agregado exitosamente a la cola" << endl;
}

void sacarCola(NodoCola*& frente, NodoCola*& fin, int& n) {
    NodoCola* aux = frente;
    n = aux->info;
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->sgte;
    }
    delete aux;
}

void insertarOrdenado(NodoLista*& lista, int valor) {
    NodoLista* nuevo = new NodoLista{valor, nullptr};
    if (!lista || (criterio * lista->info > criterio * valor)) {
        nuevo->sgte = lista;
        lista = nuevo;
    } else {
        NodoLista* temp = lista;
        while (temp->sgte && (criterio * temp->sgte->info < criterio * valor)) {
            temp = temp->sgte;
        }
        nuevo->sgte = temp->sgte;
        temp->sgte = nuevo;
    }
}

void mostrarLista(NodoLista* lista) {
    while (lista) {
        cout << lista->info << " -> ";
        lista = lista->sgte;
    }
    cout << "NULL" << endl;
}
