#include <iostream>
#include <stdlib.h>
using namespace std;

void pedirNumeros();
void ordenarArray(int *, int);
void mostrarArrayOrdenado(int *, int);

int nElementos;
int *arreglo;  // Declaración del puntero sin asignación inicial

int main() {
    cout << "*** Ordenamiento de un Arreglo ***" << endl;
    pedirNumeros();
    ordenarArray(arreglo, nElementos);
    mostrarArrayOrdenado(arreglo, nElementos);

    delete[] arreglo;  // Liberar la memoria dinámica
    return 0;
}

void pedirNumeros() {
    cout << "Ingrese cantidad de elementos: "; 
    cin >> nElementos;

    arreglo = new int[nElementos]; 
    for (int i = 0; i < nElementos; i++) {
        cout << "Ingrese elemento [" << i << "]: "; cin >> arreglo[i];
    }
}

void ordenarArray(int *vec, int nElementos) {
    int aux;
    for (int i = 0; i < nElementos - 1; i++) {
        for (int j = 0; j < nElementos - i - 1; j++) {
            if (*(vec + j) > *(vec + j + 1)) {
                aux = *(vec + j);
                *(vec + j) = *(vec + j + 1);
                *(vec + j + 1) = aux;
            }
        }
    }
}

void mostrarArrayOrdenado(int *vec, int nElementos) {
    cout << "\n*** Arreglo ordenado ***" << endl;
    for (int i = 0; i < nElementos; i++) {
        cout << "Elemento [" << i << "]: " << *(vec + i) << endl;
    }
}
