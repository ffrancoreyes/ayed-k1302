
#include <iostream>
using namespace std;

int main(){
    int num = 19, *dir_num;
    dir_num = &num;

    cout << "El número es: " << *dir_num << " y la dirección en memoria es: " << dir_num << endl;

    return 0;
}