/*Hacer un programa utilizando colas que contenga el siguiente menú:
    1. Insertar un caracter a una cola
    2. Mostrar todos los elementos de la cola
    3. Salir 
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void mostrarMenu();
void insertarCola(Nodo*&, Nodo* &, int);
void sacarCola(Nodo *&, Nodo *&, int &);

int main(){
    mostrarMenu();
    return 0;
}


void mostrarMenu(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    int opr, dato;
    do{
        cout <<"*** Menú de control colas ***" << endl;
        cout <<"1. Insertar un caracter a una cola"<< endl;
        cout <<"2. Mostrar todos los elementos de la cola" << endl;
        cout <<"3. Salir" << endl;
        cout <<"Ingrese operación: "; cin >> opr;

        switch (opr)
        {
        case 1:
            cout <<"Ingrese el valor que desea agregar a la cola: "; cin >> dato;
            insertarCola(frente, fin, dato);
            break;
        case 2:
            while(frente != NULL){
                sacarCola(frente, fin, dato);
                if(frente != NULL){
                    cout << dato << endl;
                }else{
                    cout << dato << endl;
                }
            }
            break;
        }

    }while(opr != 3);
}

void insertarCola(Nodo*&frente, Nodo* &fin, int x){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->info = x;
    nuevo_nodo->sgte = NULL;

    if (frente==NULL){
        frente = nuevo_nodo;
    }else {
        fin->sgte = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

void sacarCola(Nodo*&frente, Nodo* &fin, int &x){
    x = frente->info;
    Nodo *aux = frente;
    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->sgte;
    }
    delete aux;
}