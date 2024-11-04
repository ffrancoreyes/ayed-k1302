/*Rellenar un array de 10 números, posteriormente utilizando punteros indicar cuales son números pares y cuales impares */

#include <iostream> 
using namespace std; 

int main(){
    int numeros[10], *ptr = numeros;
    for (int i = 0; i < 10; i++){
        cout << "Ingrese num [" << i << "]: "; cin >> numeros[i];
    }



    for(int i = 0; i<10; i++){
        if((*ptr % 2) == 0){
            cout << "El número " << *ptr++ << " es par" << endl; 
        }else{
            cout << "El número " << *ptr++ << " es impar " << endl;
        }
    }
    

    return 0;
}