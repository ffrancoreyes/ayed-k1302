/*Crear un programa que pida el nombre al usuario y devuelva cuantas vocales gay en su nombre.*/
#include <iostream>
#include <string.h>
using namespace std;

void pedirNombre();
int contarVocales(char *);

char nombre[30];

int main(){
    cout << "*** contar vocales del nombre ***" << endl;
    pedirNombre();
    cout << "La cantidad de vocales en su nombre fue: " << contarVocales(nombre);
    return 0;
}

void pedirNombre(){
    cout << "Ingrese su nombre: "; 
    cin.getline(nombre,30,'\n');
    strupr(nombre);
}

int contarVocales(char *nombre){
    int contador = 0;
    while(*nombre){
        switch (*nombre)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': contador++;
        }
        nombre++;
    }
    return contador;
}