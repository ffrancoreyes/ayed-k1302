/* Transmisión de arreglos

Ejemplo: Hallar el máximo elemento de un arreglo.
*/
#include <iostream>
using namespace std;

int hallarMax(int *, int);

int main(){
    const int nElementos = 5;
    int numeros[nElementos] = {3,5,2,8,1};
    cout << "El número mayor del vector números es: " << hallarMax(numeros, nElementos);
    
    return 0;
}

int hallarMax(int *dirVec, int nElementos){
    int numMax = 0;
    
    for(int i = 0; i<nElementos; i++){
        if(*(dirVec+i)>numMax){
            numMax = *(dirVec+i);
        }
    }

    return numMax;
}