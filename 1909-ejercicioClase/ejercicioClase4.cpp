/*
Ejercicio 4: Apareo
Tomando los archivos de inscriptos “InscriptosK21” y “Inscriptos K42” generar un nuevo archivo ordenado por número de inscripción (los archivos ya están ordenados) que contenga a todos los inscriptos. 
EL archivo de salida debe tener un campo adicional llamado Prueba char[4] que debe contener “k21” o “k42 según sea el archivo de origen del que proviene el registro
El nuevo archivo se debe llamar “InscriptosMarathon2024Oct.bin” 
El diseño del archivo de salida debe ser 
    int  NroInscripcion
    char NombreApellido[50]
    char Sexo[1]
    char DNI[9]
    char Prueba [4] 


 */

#include<iostream>
#include<fstream>
#include<cstring>  // Para usar strcmp

using namespace std;

// Definición de la estructura
struct listado {
    int NroInscripcion;
    char NombreApellido[50];
    char Sexo[1];
    char DNI[9];
} regCarrera;

struct part {
    char prueba[4];
    char NombreApellido[50];
    char sexo[2];  // Tamaño 2 para incluir el terminador nulo
    int NroInscripcion;
    int posicion;
    char DNI[9];
} k21, k42;  // Definir dos variables, una para cada archivo

int main() {
    int aux;
    FILE* w;
    FILE* j;
    FILE* q;

    // Abrir solo los archivos en modo lectura
    w = fopen("corredores_21k.bin", "rb");
    j = fopen("corredores_42k.bin", "rb");
    q = fopen("InscriptosMarathon2024Oct.bin", "wb+");

    if (!w) {
        cout << "No se pudo abrir el archivo corredores_21k.bin" << endl;
        return 1;
    }

    if (!j) {
        cout << "No se pudo abrir el archivo corredores_42k.bin" << endl;
        return 1;
    }
    // K21 1-2-3-4-6 - K42 5- 7
     while (fread(&k21, sizeof(k21), 1, w) == 1 && fread(&k42, sizeof(k42), 1, j) == 1) {
        if(k21.NroInscripcion < k42.NroInscripcion){
            fwrite(&k21,sizeof(k21), 1, q);
            cout << "Nro de Inscripcion: " << k21.NroInscripcion << ", Nombre y apellido: "
            << k21.NombreApellido << ", Sexo: " << k21.sexo << ", DNI: " << k21.DNI << endl;
            
        } 
		
		if(k21.NroInscripcion > k42.NroInscripcion){
            fwrite(&k42,sizeof(k42), 1, q);
            cout << "Nro de Inscripcion: " << k42.NroInscripcion << ", Nombre y apellido: "
            << k42.NombreApellido << ", Sexo: " << k42.sexo << ", DNI: " << k42.DNI << endl;
            
        } 

		if(feof(w)){
            while(fread(&k42, sizeof(k42), 1, j) == 1){
                fwrite(&k42,sizeof(k42), 1, q);
                cout << "Nro de Inscripcion: " << k42.NroInscripcion << ", Nombre y apellido: "
                << k42.NombreApellido << ", Sexo: " << k42.sexo << ", DNI: " << k42.DNI << endl;
            }
            
        }
        else if(!feof(j)){
            while(fread(&k21, sizeof(k21), 1, w) == 1){
                fwrite(&k21,sizeof(k21), 1, q);
                cout << "Nro de Inscripcion: " << k21.NroInscripcion << ", Nombre y apellido: "
                << k21.NombreApellido << ", Sexo: " << k21.sexo << ", DNI: " << k21.DNI << endl;
            }
        
        }
    }
        return 0;
}

// Cerrar los archivos
  
