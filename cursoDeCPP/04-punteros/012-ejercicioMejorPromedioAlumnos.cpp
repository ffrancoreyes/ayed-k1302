/*Hacer una estructura llamada alumno en la cual se tendrán los siguientes campos
    -Nombre
    -Edad
    -Promedio
Pedir los datos al usuario para 3 alumnos, comprobar cual de los tres tiene el mejor promedio y posteriormente imprimir los datos del alumno
*/
#include <iostream>
using namespace std;

struct alumno{
    char nombre[30];
    int edad;
    float promedio;
}datosAlumno[3], *ptrDatosAlumno = datosAlumno;

void pedirDatosAlumnos();
void mayorPromedio(alumno *);



int main(){
    cout << "*** Mejor promedio de tres alumnos ***" << endl;
    pedirDatosAlumnos();
    
    return 0;

}

void pedirDatosAlumnos(){
    for(int i = 0; i<3; i++){
        cout << "*** Datos del alumno " << i <<  " ***" << endl;
        cout << "Ingrese nombre: "; cin.getline((ptrDatosAlumno+i)->nombre,30,'\n');
        cout << "Ingrese edad: "; cin >> (ptrDatosAlumno+i)->edad;
        cout << "Ingrese promedio: "; cin >> (ptrDatosAlumno+i)->promedio;
    }
}

void mayorPromedio(alumno *ptrDatosAlumno){
    float mayorPromedio = 0.0;
    int pos = 0;
    for(int i = 0; i<3; i++){
        if(((ptrDatosAlumno+i)->promedio) > mayorPromedio){
            mayorPromedio = (ptrDatosAlumno+i)->promedio;
            pos = i;
        }
    }
}