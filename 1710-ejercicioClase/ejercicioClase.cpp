#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int num = 9; // num es un numero entero
	int *numPuntero; // es un valor entero * puntero a un numero entero
	numPuntero = &num;  /*asigna el valor de la direccion de memeria de num a numPuntero */
	cout << "               la direccion de num  es: "<< &num << endl;
	cout << "            el valor de numPuntero  es: "<< numPuntero << endl;
	cout << "                   el valor de num  es: "<< num << endl;
	cout << "el valor en la direccion numPuntero es: "<< *numPuntero << endl;
	cout << "el valor en la direccion numPuntero es: "<< &*numPuntero << endl;
	cout << "el valor en la direccion numPuntero es: "<< *&numPuntero << endl;
	
	int num2 = 15, *num2Puntero=NULL;
	int num3 = 15, *num3Puntero=0;
	cout << "el valor del puntero num 2 Puntero es: "<< num2Puntero << endl;
	cout << "el valor del puntero num 3 Puntero es: "<< num3Puntero << endl;
	
	int *p = new int(); //pido una direccion de memoria
	int *numpuntero;
	cout << "el valor del puntero p es:" << p << endl;
	*p = 70;
	cout << *p <<endl; 
	cout << "el valor del puntero p es:" << p << endl;
	*p = *p + 18;
	cout << *p <<endl; 
		
	return 0;
}