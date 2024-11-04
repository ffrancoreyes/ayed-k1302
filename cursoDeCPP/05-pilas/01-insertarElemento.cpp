#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sgte;
};

void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);

int main(){
    Nodo *pila = NULL;
    int dato;
    cout << "*** Crear una Pila ***" << endl;
    cout << "Ingrese un número: "; cin >> dato;
    agregarPila(pila,dato);
    cout << "Ingrese otro número: "; cin >> dato;
    agregarPila(pila,dato);

    cout << "\nSacando Elementos de la pila: " << endl;
    while(pila != NULL){
        sacarPila(pila,dato);
        if(pila != NULL){
            cout << dato << ", "<<endl;
        }else{
            cout << dato << ".";
        }
    }


    return 0;

}

void agregarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo ->dato=n;
    nuevo_nodo -> sgte = pila;
    pila = nuevo_nodo;
    cout << "\nElemento " << n  << " agregado exitosamente" << endl;
}

void sacarPila(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->sgte;
    delete aux;

    cout << "\nElemento eliminado con éxito" << endl;
}