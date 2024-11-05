#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarElementoLista(Nodo *&, int);
void eliminarLista(Nodo *&, int &);

int main(){
    Nodo *lista = NULL;
    int info;
    cout << "Ingrese un número: "; cin>>info;
    insertarLista(lista,info);
    cout << "Ingrese un número: "; cin>>info;
    insertarLista(lista,info);
    cout << "Ingrese un número: "; cin>>info;
    insertarLista(lista,info);

    mostrarLista(lista);

    cout << "\nBuscar un número en la lista: "; cin >> info;
    buscarLista(lista,info); 

    cout << "Ingrese número que desea eliminar: "; cin >> info;
    eliminarElementoLista(lista, info);

    mostrarLista(lista);
    cout << "\n";
    while(lista != NULL){
        eliminarLista(lista, info);
        cout << info << " -> ";
    }

    mostrarLista(lista);

    return 0;
}

void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo(); 
    nuevo_nodo->info = n;
    Nodo *aux1 = lista;
    Nodo *aux2;
    while((aux1 != NULL) && (aux1->info < n)){ //mientras que no sea el fin de la lista && aux1 sea menor que n (para ordenar)
        aux2 = aux1;
        aux1 = aux1->sgte;
    }
    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->sgte = nuevo_nodo;
    }
    nuevo_nodo->sgte = aux1;
    cout << "Elemento insertado a lista exitosamente" << endl;
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout << actual->info << " -> ";
        actual = actual->sgte;
    }
}

void buscarLista(Nodo *lista, int n){
    bool band = false;
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){ //en caso de que sea una lista ordenada ((actual != NULL) &&(actual->info <=n))
        if(actual->info == n){
            band = true;
            break;
        }
        actual = actual->sgte;
    }
    if(band){
        cout << "\nSe encontro el elemento" << endl;
    }else{
        cout << "\nNo se encontró el elemento" << endl;
    }
}

void eliminarElementoLista(Nodo *& lista, int n){
    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;
        //mientras que no sea el fin de la lista y el número que buscamos no sea el actual
        while((aux_borrar != NULL) && (aux_borrar->info != n)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->sgte;
        }
        //en caso que el elemento no exista
        if(aux_borrar == NULL){
            cout << "El elemento no existe" << endl;

        } //en caso de que el elemento sea el inicio de la lista
        else if(anterior == NULL){
            lista = lista->sgte;
            delete aux_borrar;
        }else{
            anterior->sgte = aux_borrar->sgte;
            delete aux_borrar;
        }
    }
}

void eliminarLista(Nodo *&lista, int &n){
    Nodo *aux = new Nodo();
    aux = lista;
    n = aux->info;
    lista = aux->sgte;
    delete aux;
}
