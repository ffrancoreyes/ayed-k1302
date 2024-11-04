#include <iostream>
using namespace std;

int main(){
    int numeros[] = {1,2,3,4,5,6};
    int *ptr = numeros;

    for(int i = 0; i<6; i++){
        cout << "Elemento  [" << i << "] del vector: " << *ptr++  << endl;
        cout << "Direccion de memoria: " << &ptr[i] << endl; 
    }

    return 0;
}