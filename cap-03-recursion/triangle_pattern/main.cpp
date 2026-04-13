#include <iostream>

using namespace std;

void triangle(int a, int b) {
    if (a <= b) {
        for (int i = 0; i < a; i++) {
            cout << "*" << " ";
        }
        cout << endl;
        triangle(a + 1, b);
        for (int i = 0; i < a; i++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}


int main() {
    /* Expected output:
    * * *
    * * * *
    * * * * *
    * * * * *
    * * * *
    * * *
     */
    triangle(3, 5);
    return 0;
}