#include<iostream>
#include<cstring> 
#include <stdio.h> 
#include <string.h> 

// Para usar strcmp
using namespace std;

// Definición de la estructura
struct part {
    char Prueba[4];
    char NombreApellido[50];
    char Sexo[1];
    int NroInscripcion;
    int Posicion;
    char DNI[9];
} r;

struct listado{
    int NroInscripcion;
    char NombreApellido[50];
    char Sexo[1];
    char DNI[9];
} reg2;
void muestra(part reg);
// Prototipos de funciones
int contarRegistros(FILE* f);

// Programa principal
int main() {
    int cantidadRegistros=0,corredores21=0, corredores42 = 0;
    FILE* f;
    FILE* k21;
    FILE* k42;

    f = fopen("archivocorredores.bin", "rb");
    if (!f) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    k21 = fopen("Listado_21k.bin", "wb");
    if (!k21) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    k42 = fopen("Listado_42k.bin", "wb");
    if (!k42) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    fread(&r, sizeof(r), 1, f);
    while (!feof(f)) 
    {
        muestra(r);
        // Copio campo a campo los datos de cada registro
        reg2.NroInscripcion = r.NroInscripcion;
        strcpy(reg2.NombreApellido, r.NombreApellido);
        strcpy(reg2.Sexo, r.Sexo);
        strcpy(reg2.DNI, r.DNI);
        // Grabo un registgro en el nuevo archivo
        if (strcmp(r.Prueba, "21k") == 0) 
        {
            fwrite(&reg2, sizeof(reg2), 1, k21);
           // cout << "es 21K" << endl;
           // corredores21++;
        }
        else
        {
            fwrite(&reg2, sizeof(reg2), 1, k42);
            //cout << "es 42K" << endl;
            //corredores42++;
        }
    

        // leo el próxio registro
        fread(&r, sizeof(r), 1, f);
    
    }
    cout << "Hay en prueba 21k: "<< corredores21<< endl;
    cantidadRegistros = contarRegistros(f);
    cout << "Cantidad de registros en el archivo: " << cantidadRegistros << endl;
    cout << "Longituda archivo: " << ftell(f) << endl;
    cout << "Longituda registro: " << sizeof(r) << endl;


    // imprimo el priemer regisotro
    fseek(f, 0, SEEK_SET);
    fread(&r, sizeof(r), 1, f);
    muestra(r);

    fseek(f, sizeof(r) * 8, SEEK_SET);
    fread(&r, sizeof(r), 1, f);
    muestra(r);


    fseek(f, sizeof(r), SEEK_END);
    fread(&r, sizeof(r), 1, f);
    muestra(r);

    fclose(f);
    fclose(k21);
    fclose(k42);

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
void muestra(part reg) {
  
    cout << reg.NroInscripcion << ";" << reg.NombreApellido << ";"
        << reg.Prueba << ";" << reg.DNI << ";" << reg.Sexo << endl;
};