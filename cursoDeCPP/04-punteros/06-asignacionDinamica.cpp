/*Asignación dinámica de arreglos:

new: reserva el número de bytes solicitado por la declaración
delete: libera un bloque de bytes reservado con anterioridad.

Ejemplo: pedir al usuario n calificaciones y almacenarlas en un arreglo dinámico.

*/
#include <iostream>
#include <stdlib.h> //librería que nos permite usar el new y delete para eliminar un bloque de memoria
using namespace std;

void pedirNotas();
void mostrarNotas();

int numCalif, *calif; 

int main(){
    pedirNotas();
    mostrarNotas();
    //una vez que usamos los arreglos dinámicos y ya basicamente es memoria al cuete, podemos deletear lo que ya usamos con el delete.
    delete[] calif; //liberamos el espacio utilizado anteriormente.
    return 0;
}

void pedirNotas(){
    cout << "ingrese el número de calificaciones: "; cin >> numCalif;
    calif = new int[numCalif];

    for (int i = 0; i<numCalif; i++){
        cout << "ingrese nota " << i+1 << ": "; cin >> calif[i];
    }
}

void mostrarNotas(){
    cout << "\nlas notas de los alumnos son: " << endl;
    for(int i = 0; i<numCalif; i++){
        cout << "nota [" << i+1 <<"]: " << calif[i] << endl; 
    }
}