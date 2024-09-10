#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
void lectura();

int main(){
    lectura();
    return 0;
}

void lectura(){
    ifstream archivo;
    string texto;
    archivo.open("tecnologia.txt",ios::in);

    if(archivo.fail()){
        cout << "no se pudo abrir el archivo" << endl;
        exit(1);
    }

    while (!archivo.eof()){ //mientras no sea el final del archivo
    getline(archivo,texto);
    cout << texto << endl;
    }
    archivo.close();

}