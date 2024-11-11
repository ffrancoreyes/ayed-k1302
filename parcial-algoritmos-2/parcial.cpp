//Ejercicio hecho por Agustin Trolessi - Fabrizzio Franco Reyes - Julian Agustin Miño

#include <iostream>
#include <string.h>
using namespace std;

struct Nodo
{
    string info;
    Nodo *sgte;
};

void menu();
void ingresarCola(Nodo *&, Nodo *&, string);
void sacarCola(Nodo *&, Nodo *&, string &);
void insertarLista(Nodo *&, string);
void discriminarPacientes(Nodo *&, string &, Nodo *&, Nodo *&, Nodo *&,Nodo *&, Nodo *&, Nodo *&, Nodo *&,Nodo *&);
void mostrarLista(Nodo *);

int main()
{
    menu();
    return 0;
};

void menu()
{
    Nodo *frente = NULL, *fin = NULL;
    Nodo *frente1 = NULL, *fin1 = NULL;
    Nodo *frente2 = NULL, *fin2 = NULL;
    Nodo *frente3 = NULL, *fin3 = NULL;
    Nodo *lista = NULL;
    int opr, prioridad;
    string nombreApe;
    do
    {
        cout << "Menu de opciones:\n";
        cout << "1. Ingresar paciente nuevo\n";
        cout << "2. Mostrar siguiente paciente\n";
        cout << "0. Salir\n";
        cout << "\nIngrese opcion que desea realizar: ";
        cin >> opr;
        switch (opr)
        {
        case 1:
            cout << "Ingrese la prioridad del paciente: ";
            cin >> prioridad;
            cin.ignore();
            cout << "Ingrese el nombre y apellido del paciente: ";
            getline(cin, nombreApe);
            switch (prioridad)
            {
            case 0:
                ingresarCola(frente, fin, nombreApe);
                cout << "paciente agregado exitosamente";
                
                break;
            case 1:
                ingresarCola(frente1, fin1, nombreApe);
                cout << "paciente agregado exitosamente";
                
                break;
            case 2:
                ingresarCola(frente2, fin2, nombreApe);
                cout << "paciente agregado exitosamente";
                
                break;
            case 3:
                ingresarCola(frente3, fin3, nombreApe);
                cout << "paciente agregado exitosamente";
                
                break;
            }
            break;
        case 2:
            discriminarPacientes(lista, nombreApe, frente, fin, frente1, fin1, frente2, fin2, frente3, fin3);
            mostrarLista(lista);
            system("pause");
            break;
        }
        system("cls");
    } while (opr != 0);
}

void ingresarCola(Nodo *&frente, Nodo *&fin, string x)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->info = x;
    nuevo_nodo->sgte = NULL;
    if (frente == NULL)
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->sgte = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

void sacarCola(Nodo *&frente, Nodo *&fin, string &x)
{
    x = frente->info;
    Nodo *aux = frente;
    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->sgte;
    }
    delete aux;
}

void insertarLista(Nodo *&lista, string x)
{
    Nodo *nuevo = new Nodo{x, nullptr};
    if (!lista)
    {
        lista = nuevo;
    }
    else
    {
        Nodo *temp = lista;
        while (temp->sgte)
            temp = temp->sgte;
        temp->sgte = nuevo;
    }
}

/*Nuestro código discrimina a los pacientes por su prioridad de atención, al momento de ingresarlos, se pide la prioridad y en base a la prioridad ingresada, se la manda a la cola correspondiente, en esta función lo que se hace es vaciar en una lista, todos los elementos de prioridad 0, luego todos los elementos de prioridad 1 y finalmente todos los elementos de prioridad 2 y 3 alternando 2 elemmentos de prioridad 2 y 1 elemento de prioridad tres, hasta que se termienen */

void discriminarPacientes(Nodo *&lista, string &x, Nodo *&frente, Nodo *&fin, Nodo *&frente1, Nodo *&fin1, Nodo *&frente2, Nodo *&fin2, Nodo *&frente3, Nodo *&fin3)
{
    while (frente != NULL)
    {
        sacarCola(frente, fin, x);
        insertarLista(lista, x);
    }

    while (frente1 != NULL)
    {
        sacarCola(frente1, fin1, x);
        insertarLista(lista, x);
    }

    while (frente2 != NULL)
    {
        sacarCola(frente2, fin2, x);
        insertarLista(lista, x);
        if (frente2 != NULL)
        {
            sacarCola(frente2, fin2, x);
            insertarLista(lista, x);
        }
        if (frente3 != NULL)
        {
            sacarCola(frente3, fin3, x);
            insertarLista(lista, x);
        }
    }

    while (frente3 != NULL)
    {
        sacarCola(frente3, fin3, x);
        insertarLista(lista, x);
    }
}

void mostrarLista(Nodo* lista) {
    auto listaAux = lista;
    while (listaAux) {
        cout << listaAux->info << " -> ";
        listaAux = listaAux->sgte;
    }
    cout << endl;
}

