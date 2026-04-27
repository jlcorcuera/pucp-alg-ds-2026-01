#include <iostream>

using namespace std;

void hanoi(int n, char source, char auxiliar, char destination) {
    if (n == 0) {
        return;
    }

    hanoi(n - 1, source, destination, auxiliar);

    cout << "Mover disco " << n << " de " << source << " a " << destination << endl;

    hanoi(n - 1, auxiliar, source, destination);

}

int main() {
    int n = 2;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}