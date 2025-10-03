#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a, b, c;
    int x, y, z;
    cout << "Masukkan nilai untuk a, b, c: ";
    cin >> a >> b >> c;
    cout << "Masukkan nilai untuk x, y, z: ";
    cin >> x >> y >> z;
    cout << "\n Pointer" << endl;
    cout << "Sebelum swap: a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarPointer(&a, &b, &c);
    cout << "Setelah swap: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "\n Reference" << endl;
    cout << "Sebelum swap: x = " << x << ", y = " << y << ", z = " << z << endl;
    tukarReference(x, y, z);
    cout << "Setelah swap: x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}
