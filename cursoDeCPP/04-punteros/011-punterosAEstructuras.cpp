/**/

#include <iostream>
using namespace std;

void pedirDatos();
void mostrarDatos();

struct persona{
    char nombre[30];
    int edad;
}datosPersona, *ptrPersona = &datosPersona;

int main(){
    cout <<"*** Pedir datos de persona ***" << endl;
    pedirDatos();
    mostrarDatos();
}

void pedirDatos(){
    cout << "Ingrese nombre: ";
    cin.getline(ptrPersona->nombre,30,'\n');
    cout << "Ingrese edad: "; cin >> ptrPersona->edad; 
}

void mostrarDatos(){
    cout << "\n*** Datos Ingresados ***" << endl;
    cout << "Nombre: " << ptrPersona->nombre << endl;
    cout << "Edad: " << ptrPersona->edad << endl;
}