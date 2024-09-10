#include <iostream>
#include <stdlib.h>
#include <fstream> //librería para usar archivos
using namespace std;

void escribir();

int main()
{
    escribir();
    return 0;
}

void escribir(){
    ofstream archivo; //creamos el archivo
    archivo.open("prueba.txt",ios::out); //abrimos el archivo, como el archivo no existe, lo crea. y si ya existe, lo reemplaza.

    /*La estructura para abrir el archivo es la siguiente:
    nombreArchivo.open("direccionArchivo", modo (puede ser lectura, escritura, etc.));

    */
    if(archivo.fail()){
        cout << "no se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo<<"Hola que tal?";
    archivo<<"Agrego mas texto al archivo";
    archivo.close(); //cierro el archivo
}