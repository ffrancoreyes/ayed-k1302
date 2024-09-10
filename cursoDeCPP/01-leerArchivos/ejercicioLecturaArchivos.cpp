#include <iostream>
#include <fstream>
using namespace std;

void leerArchivo();

int main(){
    leerArchivo();
    return 0;
}

void leerArchivo(){
    ifstream archivo;
    string texto, ubicacionNombre;
    cout << "ingrese nombre o ubicación de archivo: "; 
    getline(cin,ubicacionNombre);
    archivo.open(ubicacionNombre.c_str(), ios::in);
    if(archivo.fail()){
        cout << "no se pudo abrir el archivo" << endl;
        exit(1);
    }
    while(!archivo.eof()){ //siempre poner el eof()
        getline(archivo,texto);
        cout << texto << endl;
    }
    archivo.close();

}