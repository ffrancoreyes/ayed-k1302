/*Rellenar un array con n números, posteriormente utilizando punteros determinar el menor elemento del arreglo.*/
#include <iostream>
using namespace std;

int main(){
    int numeros[10], *ptr = numeros, min = 9999999;
    for (int i = 0; i< 10 ; i++){
        cout << "ingrese numero [" << i << "]: "; cin >> numeros[i];
    }
    for(int i = 0; i<10; i++){
        if(*ptr < min){
            min = *ptr;
        }
        ptr++;
    }
    cout  << " El número minimo encontrado fue: " << min << endl;
    return 0;
}