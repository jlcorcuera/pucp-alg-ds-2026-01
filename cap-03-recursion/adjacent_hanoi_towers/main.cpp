#include <iostream>

using namespace std;

void hanoiv2(int n, char source, char auxiliar, char destination) {
    if (n == 0) {
        return;
    }

    hanoiv2(n - 1, source, auxiliar, destination);

    cout << n << ": " << source << " -> " << auxiliar << endl;

    hanoiv2(n - 1, destination, auxiliar, source);

    cout << n << ": " << auxiliar << " -> " << destination << endl;

    hanoiv2(n - 1, source, auxiliar, destination);

}


int main() {
    int n = 2;
    hanoiv2(n, 'A', 'B', 'C');
    return 0;
}