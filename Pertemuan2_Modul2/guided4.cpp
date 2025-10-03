#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main() {
    int a = 20, b = 30;
    int &ref = a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of : " << &a << endl;
    cout << "Value stured in ptrs (address of a): " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;

    //menguah nilai a lewat refrence
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a:" << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" <<a << "and b=" << b << endl;
    return 0;
}