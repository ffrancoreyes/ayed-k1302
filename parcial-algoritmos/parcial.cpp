/*Parcial de AyED - Fabrizzio Franco Reyes y  - K1302*/

#include <iostream>
using namespace std;

//estructuras
struct datos_insc {
   string nombre;
   string apellido;
   int num_insc;
   int carrera[12];
}inscripto[100];

struct pond{
   int carrera[12];
   float ponderador[12];
}valor_pond;

struct competidores{

}competidor[100];

struct lista_final{
   string nombre;
   string apellido;
   int num_insc;
}corredor[100];

//prototipos de función
void pedir_datos(datos_insc &inscripto);
void pedir_pond(pond &valor_pond);
bool participa(datos_insc &inscripto);

int main() {
   //pregunto cantidad de inscriptos
   int cont_insc = 0;
   cout << "Ingrese cantidad de inscriptos: ";
   cin >> cont_insc;
   //limpio el buffer
   cin.ignore();


   for (int i = 0; i < cont_insc; i++){
         pedir_datos(inscripto[i]);
      }
   for (int i = 0; i < cont_insc; i++){
         participa(inscripto[i]);
      }

   return 0;
}

//pedimos los datos al usuario
void pedir_datos(datos_insc &inscripto){
   cout << "Ingrese nombre: ";
   getline(cin, inscripto.nombre);

   cout << "Ingrese apellido: ";
   getline(cin, inscripto.apellido);

   cout << "Ingrese número de inscripción: ";
   cin >> inscripto.num_insc;

   cin.ignore();

   for(int i = 0; i <= 12; i++){
      cout << "Ingrese puntaje de carrera " << i << ": ";
      cin >> inscripto.carrera[i+1];
   }
   cin.ignore();
}

//pido valores del ponderador
void pedir_pond(pond &valor_pond){
   for(int i=0; i<12; i++){
      cout <<"ingrese ponderador de la carrera " << i+1 << ": ";
      cin >> valor_pond.ponderador[i];
   }

}

bool participa(datos_insc &inscripto){
   //creo un contador de carrera para sumar uno cuando la carrera tenga un puntaje mayor a 100
   int cont_carrera =0;
   bool participa = false;

   //verifico si el puntaje de cada carrera es mayor a 100, en caso positivo sumo uno al contador
   for(int i=0; i<12;i++){
      if(inscripto.carrera[i]>=100){
         cont_carrera+=1;
      }
   }
   if(cont_carrera >= 6){
      participa = true;
   }


   return participa;
}
