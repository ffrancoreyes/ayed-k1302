#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sgte;
};

void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void sacarCola(Nodo *&, Nodo *&, int &);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;
    cout << "*** Ingresando elementos de la cola ***" << endl;
    cout << "Ingrese un numero: "; cin >> dato;
    insertarCola(frente,fin,dato);
    cout << "Ingrese un numero: "; cin >> dato;
    insertarCola(frente,fin,dato);
    cout << "Ingrese un numero: "; cin >> dato;
    insertarCola(frente,fin,dato);

    cout << "*** Eliminar Elementos de la cola ***" << endl;
    //eliminar los elementos de la cola
    while(frente != NULL){
        sacarCola(frente, fin,dato);
        if(frente != NULL){
            cout <<dato << " , ";
        }else{
            cout << dato << ".";
        }
    }

    return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = NULL;
    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin->sgte = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
    return (frente == NULL) ? true : false;
}

void sacarCola(Nodo *&frente, Nodo *&fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;
    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->sgte;
    }
    delete aux;
}