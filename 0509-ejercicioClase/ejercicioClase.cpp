/* Ejercicio en equipo parte 1

Escribir el código C++ en equipo, mostrar las salidas 
y explicar las funciones que utilizaron para resolver.

1)Asignar la palabra "sabiduría" a un string llamado sNombre.
2)Asignar la palabra "conocimiento" a un char[10] llamado cNombre.
3)Contar cuántas letras tiene sNombre.
4)Contar cuántas letras tiene cNombre.
5)Cuál es la 3er letra de sNombre.
6)Cuál es la 3er letra de cNombre.
7)Asignar cNombre a sNombre.
8)Asignar sNombre a cNombre. */

/*Grupo 1: Trolessi Agustin Ignacio - Robert Ohanyan - Gabriela Loza Mamani - Salvador Merlotti - Fabrizzio Franco Reyes */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string sNombre = "sabiduria";
char cNombre[14] = "conocimiento";  // El tamaño debe ser 14 para almacenar '\0'

void contarLetras(string sNombre, char cNombre[]);
void tercerLetra(string sNombre, char cNombre[]);
void intercambiar(string sNombre, char cNombre[]);

int main() {
    contarLetras(sNombre, cNombre);
    tercerLetra(sNombre,cNombre);
    intercambiar(sNombre, cNombre);
    return 0;
}

//función para contar letras: Defino dos variables que me van a servir para guardar las longitudes del texto ingresado. Posteriormente calculo su longitud con la correspondiente función como lo son strlen() y size(). Finalmente, imprimo las longitudes de las variables.
void contarLetras(string sNombre, char cNombre[]) {
    int longitudS = 0, longitudC = 0;
    longitudC = strlen(cNombre); 
    longitudS = sNombre.size();
    cout << "Longitud de sNombre: " << longitudS << endl;
    cout << "Longitud de cNombre: " << longitudC << endl;

}

void tercerLetra(string sNombre, char cNombre[]){
    char letraString  = sNombre[2];
    char letraChar = cNombre[2]; 
    
    cout << "la tercera letra de "<< sNombre << " es: " << letraString << endl; //Muestro en pantalla los caracteres obtenidos
    cout << "la tercera letra de "<< cNombre << " es: " << letraChar << endl;  
    
}

void intercambiar(string sNombre, char cNombre[]){
    cout << "Antes del intercambio:" << endl;
    cout << "cNombre: " << cNombre << endl; //Muestro en pantalla los caracteres que contienen tanto
    cout << "sNombre: " << sNombre << endl; //La variable char como el String
     
    strcpy(cNombre, sNombre.c_str()); //Copio el contenido del String sNombre en el caracter cNombre
    sNombre ="Conocimiento"; //Cambio el contenido del sNombre
     
    cout << "Despues del intercambio:" <<endl;
    cout << "cNombre: " << cNombre << endl; //Muestro el intercambio en pantalla
    cout << "sNombre " << sNombre << endl; 
    
    
}
