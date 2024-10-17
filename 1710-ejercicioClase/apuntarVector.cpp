#include <iostream>
using namespace std;

int main(){
    /*lo que hacemos primero es declarar nuestro vector con 4 valores. */
    int vec[4] = {11,24,232,412};
    //inicializamos el puntero para poder acceder luego a su ubicación en memora
    int *punteroVec;
    punteroVec = &vec[0];
    //imprimimos el valor, la ubicación del puntero
    for (int i = 0; i<4; i++){
        cout << "ubicacion de " << vec[i] << " es: " << &vec[i] << " " << *(punteroVec+i) << endl;
    }
    
    return 0;

}
