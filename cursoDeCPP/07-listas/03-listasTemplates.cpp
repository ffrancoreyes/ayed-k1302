#include <iostream>
#include <stdlib.h>
using namespace std;

// Estructura del nodo
template <typename T>
struct Nodo {
    T info;
    Nodo* sig;
};

// Funciones para manipular la lista
template <typename T> void insertarPrimero(Nodo<T>*& lista, T valor);
template <typename T> void insertarUltimo(Nodo<T>*& lista, T valor);
template <typename T> void insertarPosicion(Nodo<T>*& lista, T valor, int pos);
template <typename T> void insertarOrdenado(Nodo<T>*& lista, T valor);
template <typename T> Nodo<T>* buscar(Nodo<T>* lista, T valor);
template <typename T> void insertarOrdenadoSinRepetir(Nodo<T>*& lista, T valor);
void cambiarCriterioOrdenamiento();
template <typename T> void eliminarPrimero(Nodo<T>*& lista);
template <typename T> void eliminarUltimo(Nodo<T>*& lista);
template <typename T> void eliminarValor(Nodo<T>*& lista, T valor);
template <typename T> void eliminarTodos(Nodo<T>*& lista);
template <typename T> void mostrarLista(Nodo<T>* lista, bool eliminar = false);

int criterio = 1;  // Criterio de ordenamiento (1 = ascendente, -1 = descendente)

void menu() {
    Nodo<int>* lista = nullptr;  // Tipo int por defecto
    int opr, valor, pos;
    do {
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
        cout << "\nIngrese opcion que desea realizar: ";
        cin >> opr;
        
        switch (opr) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarPrimero(lista, valor);
                break;
            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarUltimo(lista, valor);
                break;
            case 3:
                cout << "Ingrese valor y posicion: ";
                cin >> valor >> pos;
                insertarPosicion(lista, valor, pos);
                break;
            case 4:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarOrdenado(lista, valor);
                break;
            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                cout << (buscar(lista, valor) ? "Encontrado\n" : "No encontrado\n");
                break;
            case 6:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarOrdenadoSinRepetir(lista, valor);
                break;
            case 7:
                cambiarCriterioOrdenamiento();
                break;
            case 8:
                eliminarPrimero(lista);
                break;
            case 9:
                eliminarUltimo(lista);
                break;
            case 10:
                cout << "Ingrese valor a eliminar: ";
                cin >> valor;
                eliminarValor(lista, valor);
                break;
            case 11:
                eliminarTodos(lista);
                break;
            case 12:
                mostrarLista(lista);
                break;
            case 13:
                mostrarLista(lista, true);
                break;
            case 0:
                eliminarTodos(lista);
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opr != 0);
}

// Implementación de las funciones
template <typename T>
void insertarPrimero(Nodo<T>*& lista, T valor) {
    Nodo<T>* nuevo = new Nodo<T>{valor, lista};
    lista = nuevo;
}

template <typename T>
void insertarUltimo(Nodo<T>*& lista, T valor) {
    Nodo<T>* nuevo = new Nodo<T>{valor, nullptr};
    if (!lista) {
        lista = nuevo;
    } else {
        Nodo<T>* temp = lista;
        while (temp->sig) temp = temp->sig;
        temp->sig = nuevo;
    }
}

template <typename T>
void insertarPosicion(Nodo<T>*& lista, T valor, int pos) {
    if (pos == 0) {
        insertarPrimero(lista, valor);
        return;
    }
    Nodo<T>* temp = lista;
    for (int i = 0; temp && i < pos - 1; i++) {
        temp = temp->sig;
    }
    if (temp) {
        Nodo<T>* nuevo = new Nodo<T>{valor, temp->sig};
        temp->sig = nuevo;
    } else {
        cout << "Posicion fuera de rango\n";
    }
}

template <typename T>
void insertarOrdenado(Nodo<T>*& lista, T valor) {
    Nodo<T>* nuevo = new Nodo<T>{valor, nullptr};
    if (!lista || (criterio * lista->info > criterio * valor)) {
        nuevo->sig = lista;
        lista = nuevo;
    } else {
        Nodo<T>* temp = lista;
        while (temp->sig && (criterio * temp->sig->info < criterio * valor)) {
            temp = temp->sig;
        }
        nuevo->sig = temp->sig;
        temp->sig = nuevo;
    }
}

template <typename T>
Nodo<T>* buscar(Nodo<T>* lista, T valor) {
    while (lista && lista->info != valor) {
        lista = lista->sig;
    }
    return lista;
}

template <typename T>
void insertarOrdenadoSinRepetir(Nodo<T>*& lista, T valor) {
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

template <typename T>
void eliminarPrimero(Nodo<T>*& lista) {
    if (lista) {
        Nodo<T>* temp = lista;
        lista = lista->sig;
        delete temp;
    }
}

template <typename T>
void eliminarUltimo(Nodo<T>*& lista) {
    if (lista) {
        if (!lista->sig) {
            delete lista;
            lista = nullptr;
        } else {
            Nodo<T>* temp = lista;
            while (temp->sig->sig) temp = temp->sig;
            delete temp->sig;
            temp->sig = nullptr;
        }
    }
}

template <typename T>
void eliminarValor(Nodo<T>*& lista, T valor) {
    if (!lista) return;
    if (lista->info == valor) {
        eliminarPrimero(lista);
        return;
    }
    Nodo<T>* temp = lista;
    while (temp->sig && temp->sig->info != valor) temp = temp->sig;
    if (temp->sig) {
        Nodo<T>* aEliminar = temp->sig;
        temp->sig = temp->sig->sig;
        delete aEliminar;
    } else {
        cout << "Valor no encontrado en la lista\n";
    }
}

template <typename T>
void eliminarTodos(Nodo<T>*& lista) {
    while (lista) eliminarPrimero(lista);
}

template <typename T>
void mostrarLista(Nodo<T>* lista, bool eliminar) {
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
