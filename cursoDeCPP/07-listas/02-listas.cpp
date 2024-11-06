#include <iostream>
#include <stdlib.h>
using namespace std;

// Estructura del nodo
struct Nodo {
    int info;
    Nodo* sig;
};

// Funciones para manipular la lista
void insertarPrimero(Nodo*& lista, int valor);
void insertarUltimo(Nodo*& lista, int valor);
void insertarPosicion(Nodo*& lista, int valor, int pos);
void insertarOrdenado(Nodo*& lista, int valor);
Nodo* buscar(Nodo* lista, int valor);
void insertarOrdenadoSinRepetir(Nodo*& lista, int valor);
void cambiarCriterioOrdenamiento();
void eliminarPrimero(Nodo*& lista);
void eliminarUltimo(Nodo*& lista);
void eliminarValor(Nodo*& lista, int valor);
void eliminarTodos(Nodo*& lista);
void mostrarLista(Nodo* lista, bool eliminar = false);

int criterio = 1;  // Criterio de ordenamiento (1 = ascendente, -1 = descendente)

void menu() {
    Nodo* lista = nullptr;
    int opr, valor, pos;
    do{
        cout << "Menu de opciones:\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Insertar en una posicion\n";
        cout << "4. Insertar ordenado\n";
        cout << "5. Buscar un valor\n";
        cout << "6. Insertar ordenado sin repetir\n";
        cout << "7. Cambiar criterio de ordenamiento\n";
        cout << "8. Eliminar primer nodo\n";
        cout << "9. Eliminar ultimo nodo\n";
        cout << "10. Eliminar un nodo por valor\n";
        cout << "11. Eliminar todos los nodos\n";
        cout << "12. Mostrar todos los valores (sin eliminar)\n";
        cout << "13. Mostrar todos los valores (eliminando)\n";
        cout << "0. Salir\n";
        cout << "\nIngrese opcion que desea realizar: "; cin >> opr;
        switch (opr) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarPrimero(lista, valor);
                system("pause");
                break;
            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarUltimo(lista, valor);
                system("pause");
                break;
            case 3:
                cout << "Ingrese valor y posicion: ";
                cin >> valor >> pos;
                insertarPosicion(lista, valor, pos);
                system("pause");
                break;
            case 4:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarOrdenado(lista, valor);
                system("pause");
                break;
            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                cout << (buscar(lista, valor) ? "Encontrado\n" : "No encontrado\n");
                system("pause");
                break;
            case 6:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarOrdenadoSinRepetir(lista, valor);
                system("pause");
                break;
            case 7:
                cambiarCriterioOrdenamiento();
                system("pause");
                break;
            case 8:
                eliminarPrimero(lista);
                system("pause");
                break;
            case 9:
                eliminarUltimo(lista);
                system("pause");
                break;
            case 10:
                cout << "Ingrese valor a eliminar: ";
                cin >> valor;
                eliminarValor(lista, valor);
                system("pause");
                break;
            case 11:
                eliminarTodos(lista);
                system("pause");
                break;
            case 12:
                mostrarLista(lista);
                system("pause");
                break;
            case 13:
                mostrarLista(lista, true);
                system("pause");
                break;
            case 0:
                eliminarTodos(lista);
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    system("cls");
    } while (opr != 0);
    
    
}

// Implementación de las funciones

void insertarPrimero(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo{valor, lista};
    lista = nuevo;
}

void insertarUltimo(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (!lista) {
        lista = nuevo;
    } else {
        Nodo* temp = lista;
        while (temp->sig) temp = temp->sig;
        temp->sig = nuevo;
    }
}

void insertarPosicion(Nodo*& lista, int valor, int pos) {
    if (pos == 0) {
        insertarPrimero(lista, valor);
        return;
    }
    Nodo* temp = lista;
    for (int i = 0; temp && i < pos - 1; i++) {
        temp = temp->sig;
    }
    if (temp) {
        Nodo* nuevo = new Nodo{valor, temp->sig};
        temp->sig = nuevo;
    } else {
        cout << "Posicion fuera de rango\n";
    }
}

void insertarOrdenado(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (!lista || (criterio * lista->info > criterio * valor)) {
        nuevo->sig = lista;
        lista = nuevo;
    } else {
        Nodo* temp = lista;
        while (temp->sig && (criterio * temp->sig->info < criterio * valor)) {
            temp = temp->sig;
        }
        nuevo->sig = temp->sig;
        temp->sig = nuevo;
    }
}

Nodo* buscar(Nodo* lista, int valor) {
    while (lista && lista->info != valor) {
        lista = lista->sig;
    }
    return lista;
}

void insertarOrdenadoSinRepetir(Nodo*& lista, int valor) {
    if (!buscar(lista, valor)) {
        insertarOrdenado(lista, valor);
    } else {
        cout << "Valor ya existe en la lista\n";
    }
}

void cambiarCriterioOrdenamiento() {
    criterio *= -1;
    cout << "Criterio de orden cambiado a " << (criterio == 1 ? "ascendente" : "descendente") << endl;
}

void eliminarPrimero(Nodo*& lista) {
    if (lista) {
        Nodo* temp = lista;
        lista = lista->sig;
        delete temp;
    }
}

void eliminarUltimo(Nodo*& lista) {
    if (lista) {
        if (!lista->sig) {
            delete lista;
            lista = nullptr;
        } else {
            Nodo* temp = lista;
            while (temp->sig->sig) temp = temp->sig;
            delete temp->sig;
            temp->sig = nullptr;
        }
    }
}

void eliminarValor(Nodo*& lista, int valor) {
    if (!lista) return;
    if (lista->info == valor) {
        eliminarPrimero(lista);
        return;
    }
    Nodo* temp = lista;
    while (temp->sig && temp->sig->info != valor) temp = temp->sig;
    if (temp->sig) {
        Nodo* aEliminar = temp->sig;
        temp->sig = temp->sig->sig;
        delete aEliminar;
    } else {
        cout << "Valor no encontrado en la lista\n";
    }
}

void eliminarTodos(Nodo*& lista) {
    while (lista) eliminarPrimero(lista);
}

void mostrarLista(Nodo* lista, bool eliminar) {
    while (lista) {
        cout << lista->info << " -> ";
        if (eliminar) eliminarPrimero(lista);
        lista = lista->sig;
    }
    cout << endl;
}

// Función principal
int main() {
    menu();
    return 0;
}
