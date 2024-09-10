#include<iostream>
#include <fstream>
#include<cstring>  // Para usar strcmp

using namespace std;



// Definición de la estructura

struct part {

    char prueba[4];

    char NombreApellido[50];

    char sexo[1];

    int NroInscripcion;

    int posicion;

    char DNI[9];

} r;



// Prototipos de funciones

int contarRegistros(FILE* f);



// Programa principal

int main() {

    int cantidadRegistros;

    FILE* f;

    

    f = fopen("archivocorredores.bin", "rb");

    if (!f) {

        cerr << "No se pudo abrir el archivo." << endl;

        return 1;

    }



    fread(&r, sizeof(r), 1, f);

     while (!feof(f)) {

        cout << "Nombre y apellido: " << r.NombreApellido << ", Prueba: "

            << r.prueba << ", Sexo: " << r.sexo << ", Nro de Inscripcion: "

            << r.NroInscripcion << ", Posicion: " << r.posicion

            << ", DNI: " << r.DNI << endl;

            fread(&r, sizeof(r), 1, f);

    }



    cantidadRegistros = contarRegistros(f);

    cout << "Cantidad de registros en el archivo: " << cantidadRegistros << endl;



    fclose(f);

    return 0;

}



// Desarrollo de funciones

int contarRegistros(FILE* f) {

    int cantReg;

    long pos = ftell(f);  // Guarda la posición actual

    fseek(f, 0, SEEK_END);  // Mueve el puntero al final del archivo

    cantReg = ftell(f) / sizeof(r);  // Calcula la cantidad de registros

    fseek(f, pos, SEEK_SET);  // Vuelve a la posición original

    return cantReg;

}