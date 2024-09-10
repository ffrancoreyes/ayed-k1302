#include <iostream>
#include <fstream>
using namespace std;
void agregarTexto();

int main(){
    agregarTexto();
    return 0;
}

void agregarTexto(){
    ofstream archivo;
    string ubicacion, texto;
    cout <<"ingrese la ubicación o nombre del archivo: ";
    getline(cin, ubicacion);
    archivo.open(ubicacion.c_str(),ios::app);
    if(archivo.fail()){
        cout <<"el archivo no se pudo abrir"<< endl;
        exit(1);
    }
    cout << "ingrese el texto que desea agregar: ";
    getline(cin,texto);
    archivo << texto;

    archivo.close();
}