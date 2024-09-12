/*
Recursividad: Es cuando una función se llama a si misma dentro de la misma función.

*/
#include <iostream>
using namespace std;
int factorial(int n);
int potencia(int n, int exponente);
int main()
{
	int a = 5;
	cout << "El Factorial de " << a << " es " << factorial(a)<<endl;
	cout << a << " elevado a " << 0 << " es " << potencia(a, 0) << endl;
	cout << a << " elevado a " << 1 << " es " << potencia(a, 1) << endl;
	cout << a << " elevado a " << 2 << " es " << potencia(a, 2) << endl;
	cout << a << " elevado a " << 3 << " es " << potencia(a, 3) << endl;
	return 0;
}
/* Función recursiva para cálculo de factoriales */
int factorial(int n) {
	if (n < 0) return 0;
	else if (n > 1) return n * factorial(n - 1); /* Recursividad */
	return 1; /* Condición de terminación, n == 1 */
};

int potencia(int n, int exponente)
{	
	if (exponente > 0)
	return n * potencia(n, exponente - 1);
	else return 1;
};
