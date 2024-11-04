/*Comprobar si un número es par o impar, selañar la posición en memoria donde se está guardando el número */
#include <iostream>
using namespace std;

int main(){
    int numA, *ptr = &numA;
    cout << "ingrese numA: "; cin >> numA;
    if((*ptr % 2) == 0){
        cout << "el número " << *ptr <<  "  es par" << endl;
        cout << "su dirección de memoria es: " << ptr;
    }else{
        cout << "el número " << *ptr <<  "  es impar" << endl;
        cout << "su dirección de memoria es: " << ptr;
    }

    return 0;
}