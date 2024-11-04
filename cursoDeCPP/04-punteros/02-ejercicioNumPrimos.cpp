#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int numA, *ptr = &numA;

    cout << "Ingrese un número: "; 
    cin >> *ptr;

    if (*ptr < 2) {
        cout << "No es primo" << endl;
    } else if (*ptr == 2) {
        cout << "El número es primo" << endl;  
    } else if (*ptr % 2 == 0) {
        cout << "No es primo" << endl;  
    } else {
        bool primo = true;  
        for (int i = 3; i <= sqrt(*ptr); i += 2) {
            if (*ptr % i == 0) {
                cout << "No es primo" << endl;
                primo = false;  
                break;  
            }
        }
        if (primo) {
            cout << "El número es primo" << endl;
        }
    }

    
    cout << "La posición de memoria del número es: " << ptr << endl;

    return 0;
}
