/*Hacer un programa que guarde los datos de clientes de un banco, que luego loa almacene en una cola y por último muerte los clientes en el orden correcto.*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Nodo{
    string info;
    Nodo *sgte;
};

void insertarCola(Nodo*&, Nodo* &, string);
void sacarCola(Nodo *&, Nodo *&, string &);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    string info;
    cout << "Ingrese nombre de persona: ";
    getline(cin,info);
    insertarCola(frente, fin, info);
    cout << "Ingrese nombre de persona: ";
    getline(cin,info);
    insertarCola(frente, fin, info);
    while(frente != NULL){
        sacarCola(frente, fin, info);
        if(frente != NULL){
            cout << info << endl;
        }else{
            cout << info << endl;
        }
    }
    return 0;
}

void insertarCola(Nodo*&frente, Nodo* &fin, string x){
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

void sacarCola(Nodo*&frente, Nodo* &fin, string &x){
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