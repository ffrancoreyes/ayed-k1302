#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sgte;
};

int nElementos, *ptrElem;
Nodo *pila = NULL;


void pedirNum();
void insertarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void mostrarPila();

int main(){
    cout << "*** Ingresar valores en una pila ***" << endl;
    pedirNum();
    mostrarPila();
    
    delete[] ptrElem;

    return 0;
}

void pedirNum(){
    cout << "Ingrese cantidad de elementos de la pila: ";
    cin >> nElementos;
    ptrElem = new int[nElementos];
    for(int i = 0; i < nElementos; i++){
        cout << "Ingrese numero [" << i + 1 << "]: ";
        cin >> ptrElem[i];
        insertarPila(pila, ptrElem[i]);
    }
}

void insertarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = pila;
    pila = nuevo_nodo;
    cout << "Elemento ingresado con éxito" << endl;
}

void sacarPila(Nodo *&pila, int &n){
    if (pila != NULL) {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->sgte;
        delete aux;
    }
}

void mostrarPila(){
    int dato;
    cout << "\n*** Mostrando todos los elementos de la pila ***" << endl;
    while(pila != NULL){
        sacarPila(pila, dato);
        cout << dato << endl;  
    }
}
