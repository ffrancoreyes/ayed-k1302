/*
Cambiar el archivo de corredores para que cree dos archivos, uno de corredores de 21K y 42K

*/

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
    FILE* w;
    FILE* j;

    

    f = fopen("archivocorredores.bin", "rb");
    w = fopen("corredores_21k.bin", "wb");
    j = fopen("corredores_42k.bin", "wb");


    if (f == NULL || w == NULL || j == NULL) {
        perror("El archivo no se pudo abrir");
        return 1;
    }



    fread(&r, sizeof(r), 1, f);

    while (!feof(f)) {
        if(strcmp(r.prueba,"21k") == 0){
            fwrite(&r,sizeof(r), 1, w);
            cout << "Nombre y apellido: " << r.NombreApellido << ", Prueba: "
            << r.prueba << ", Sexo: " << r.sexo << ", Nro de Inscripcion: "
            << r.NroInscripcion << ", Posicion: " << r.posicion
            << ", DNI: " << r.DNI << endl; 
                
            
        } else if(strcmp(r.prueba,"42k") == 0){
            fwrite(&r,sizeof(r), 1, j);
            
            cout << "Nombre y apellido: " << r.NombreApellido << ", Prueba: "
            << r.prueba << ", Sexo: " << r.sexo << ", Nro de Inscripcion: "
            << r.NroInscripcion << ", Posicion: " << r.posicion
            << ", DNI: " << r.DNI << endl;
            
            
        } else{
            cout << "No se pudo completar el proceso" << endl;
        }
    

        fread(&r, sizeof(r), 1, f);
    }
    cantidadRegistros = contarRegistros(f);

    cout << "Cantidad de registros en el archivo: " << cantidadRegistros << endl;



    fclose(f);
    fclose(w);
    fclose(j);

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