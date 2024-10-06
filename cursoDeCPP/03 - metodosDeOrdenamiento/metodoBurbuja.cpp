/*
Método de ordenamiento de
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int numeros[] = {4,6,1,5,3,2};
    //4,2,1,3,5,6
    int i,j,aux;
    for(i=0;i<6;i++){
        for(j= 0; j<6; j++){
            if(numeros[j] > numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
            cout << numeros[j] << " ";
        }
        cout << "\n";
    }
    cout << "Ordenado de manera ASC: ";
    for(i=0;i<6; i++){
        cout << numeros[i]<< " ";
    }
    cout << "\nOrdenado de manera DESC: ";
    for(i=5; i>=0; i--){
        cout << numeros[i] << " ";
    }
    return 0;
}