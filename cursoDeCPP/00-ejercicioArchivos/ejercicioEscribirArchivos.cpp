#include <iostream>
#include <fstream>
using namespace std;

void escribirArchivo();

int main(){
    escribirArchivo();
    return 0;
}


void escribirArchivo(){
    string nombreArchivo, frase;
    int cantidadFrases = 0;
    ofstream archivo;

    //pedimos la información al usuario
    cout << "ingrese el nombre del archivo: "; 
    getline(cin,nombreArchivo);
    
    cout << "cuantas frases desea ingresar?: "; cin >> cantidadFrases;
    cin.ignore();

    //creamos el archivo con lo que el usuario pida
    archivo.open(nombreArchivo.c_str(),ios::out);

    for (int i = 0; i < cantidadFrases; i++)
    {
        cout << "ingrese frase " << i+1 << ": ";
        getline(cin,frase);
        archivo<<frase << endl;
        cin.ignore();
        
    }
}