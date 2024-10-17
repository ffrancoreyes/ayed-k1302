#include <iostream>
using namespace std;

int main(){
    double vec[4] = {11,24,232,412};
    double *punteroVec;
    punteroVec = &vec[0];
    for (int i = 0; i<4; i++){
        cout << "ubicacion de " << vec[i] << " es: " << &vec[i] << " " << punteroVec+i << endl;
    }
    cout << *(punteroVec+2);

    //debemos resolver esta parte porque solo apunta a la misma dirección, a menos que todo el array se guarde en el mismo lugar, andamos troleando en eso
    //Le preguntamos de ultima, pero mepa que el array guarda una sola direccion
    //mepa que si, pero ante la duda la mas 
    
    return 0;

}
