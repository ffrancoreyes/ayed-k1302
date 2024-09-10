/*
    Ejercicio en equipo parte 2
Escribir el código c++ en equipo , mostrar las salidas y explicar las funciones que utilizaron para resolver 
Asignar la palabra “El ignorante afirma, el sabio duda y reflexiona.
1.	” a un string llamado sNombre
2.	Asignar la palabra “El ignorante afirma, el sabio duda y reflexiona.
3.	” a un char[50] llamado cNombre
4.	 Contar cuantas letras tiene sNombre
5.	Contar cuantas letras tiene cNombre
6.	Cual es la 10ma letra de cNombre
7.	Cual es la 10ma letra de sNombre
8.	Asignar sNombre a cNombre
9.	Asignar cNombre a sNombre
10.	Determinar si la letra ‘A’ se encuentra en cNombre y en que posición
11.	Determinar si la letra ‘s’ se encuentra en cNombre y en que posición

 */

/*Grupo 1: Trolessi Agustin Ignacio - Robert Ohanyan - Gabriela Loza Mamani - Salvador Merlotti - Fabrizzio Franco Reyes */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//declaramos las variables que vamos a usar a lo largo dek programa
string sNombre = "El ignorante afirma, el sabio duda y reflexiona.";
char cNombre[50] = "El ignorante afirma, el sabio duda y reflexiona.";  

void contarLetras(string sNombre, char cNombre[]);
void decimaLetra(string sNombre, char cNombre[]);
void intercambiar(string sNombre, char cNombre[]);
void determinar(string sNombre, char cNombre[]);

int main() {
    //ahora llamamos en el main las funciones que vamos a usar.
    contarLetras(sNombre, cNombre);
    decimaLetra(sNombre, cNombre);
    intercambiar(sNombre, cNombre);
    determinar(sNombre, cNombre);
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
//funcion para saber cual es la décima letra: Defino dos variables que van a guardar el valor de la posición que nosotros elegimos, en este caso la 9 debido a que el array normalmente empieza en 0. Posteriormente imprimimos
void decimaLetra(string sNombre, char cNombre[]){
    char letraString  = sNombre[9];
    char letraChar = cNombre[9];
    
    cout << "la tercera letra de "<< sNombre << " es: " << letraString << endl;
    cout << "la tercera letra de "<< cNombre << " es: " << letraChar << endl;
    
}

void intercambiar(string sNombre, char cNombre[]){
    cout << "Antes del intercambio:" << endl;
    cout << "cNombre: " << cNombre <<endl;//Muestro en pantalla los caracteres que contienen tanto
    cout << "sNombre: " << sNombre << endl; //La variable char como el String
     
    strcpy(cNombre, sNombre.c_str()); //Copio el contenido del String sNombre en el caracter cNombre
    sNombre ="El ignorante afirma, el sabio duda y reflexiona"; //Cambio el contenido del sNombre

    cout << "Despues del intercambio:" <<endl;
    cout << "cNombre: " << cNombre << endl; //Muestro el intercambio en pantalla
    cout << "sNombre " << sNombre << endl;
    
    
}

//función para determinar si la letra se encontró o no
void determinar(string sNombre, char cNombre[]){
    bool encontrarC = false, encontrarS;
    char sNombreChar[50];

    //en estas dos líneas de código [78 y 79], usamos chatGPT debido a que no comprendíamos como solucionar el problema de convertir de String a Char.
    strncpy(sNombreChar, sNombre.c_str(), sizeof(sNombreChar) - 1);
    sNombreChar[sizeof(sNombreChar) - 1] = '\0';  // Asegurarse de que la cadena esté terminada en nulo
    
    strcpy(cNombre, sNombreChar);

    for(int i = 0; i < 50; i++) {
        if (cNombre[i] == 'A') {
            cout << "Se encontró la letra A en la posición: " << i + 1<< endl;
            encontrarC = true;
        }
        if (sNombreChar[i] == 's') {
            cout << "Se encontró la letra s en la posición: " << i + 1 << endl;
            encontrarS = true;
        }
    }

    if(encontrarC == false){
        cout << "no se encontró la letra A" << endl;
    }

    if(encontrarS == false){
        cout << "no se encontró la letra s" << endl;
    }
    
}
