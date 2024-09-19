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

int main(){
    FILE* w;
    FILE* j;
    FILE* q;
    //abro solo los archivos en modo lectura
    w = fopen("corredores_21k.bin", "rb");
    j = fopen("corredores_42k.bin", "rb");
    q = fopen("solomujeres.bin", "wb+");
    
    if(!w){
        cout << "no se pudo abrir el archivo corredores_21k.bin" << endl;
    }
    if(!j){
        cout << "no se pudo abrir el archivo corredores_42k.bin" << endl;
    }
    fread(&r, sizeof(r), 1, w);
    fread(&r, sizeof(r), 1, j);
    while(!feof(w) && !feof(j)){

        //revisar porque solo lee lo que viene siendo la parte de 42k, no la de 21k, esa se la pasa por la raja completamente
        if(strcmp(r.sexo,"F") == 0){
            fwrite(&r,sizeof(r), 1, q);
            cout << "Nombre y apellido: " << r.NombreApellido << ", Prueba: " << r.prueba  << ", Nro de Inscripcion: " << r.NroInscripcion << ", DNI: " << r.DNI << endl; 
        }
        //dando vuelta esto, aparecen 2 de 21k y 1 de 42k, el error seguramente está en esto de acá
        fread(&r, sizeof(r), 1, j);
        fread(&r, sizeof(r), 1, w);
    }
    /*
    fread(&r, sizeof(r), 1, j);
    while(!feof(j)){
        if(strcmp(r.sexo,"F") == 0){
            fwrite(&r,sizeof(r), 1, q);
            cout << "Nombre y apellido: " << r.NombreApellido << ", Prueba: " << r.prueba  << ", Nro de Inscripcion: " << r.NroInscripcion << ", DNI: " << r.DNI << endl; 
        }
        fread(&r, sizeof(r), 1, j);
    }
    */   
    return 0;
    //if (r.inscripcion)
    /*if nro posicion de 21k < niro de inscripcion de 42k
    si es el 21, proceso el de 21k
    si es el 24, proceso el de 42k
    leer con un while hasta encontrar F (YA NO SE CONSIDERA EL SEXO, LUEGO)
    leo hasta que aparezca F o hasta el final del archivo
    */
}