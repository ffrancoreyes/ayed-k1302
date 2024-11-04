/*Transmisión de direcciones

ejemplo: intercambiar el valor de 2 variables
*/
#include <iostream>
using namespace std;
void intercambio(float *, float *);

int main(){
    float numA = 19.6, numB = 20.3;
    cout << "primer número: " << numA << endl;
    cout << "segundo número: " << numB << endl;

    intercambio(&numA, &numB); //le doy la dirección de la memoria donde están guardadas mis variables.
    cout << "\nIntercambio realizado" << endl;
    cout << "primer número: " << numA << endl;
    cout << "segundo número: " << numB << endl;


    return 0;
}

void intercambio(float *dirNumA, float *dirNumB){
    float aux;
    aux = *dirNumA;
    *dirNumA = *dirNumB;
    *dirNumB = aux;
}