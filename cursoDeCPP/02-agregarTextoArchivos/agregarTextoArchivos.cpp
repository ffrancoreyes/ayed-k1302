#include<iostream>
#include<fstream>
using namespace std;

void agregarTexto();

int main(){
    agregarTexto();
    return 0;
}

void agregarTexto(){
    ofstream archivo;
    string texto;
    archivo.open("prueba.txt",ios::app); //abrimos el archivo para añadir texto en el
    if(archivo.fail()){
        cout << "no se pudo abrir el archivo" << endl;
        exit(1);
    }

    cout << "digite el texto que quiere agregar:  "; 
    getline(cin,texto);
    archivo<<texto;

    archivo.close();
}