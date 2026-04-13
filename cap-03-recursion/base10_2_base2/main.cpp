#include <iostream>

using namespace std;

void print_binary_representation(int number) {
    if (number != 0) {
        int current_bit = number % 2;
        print_binary_representation(number / 2);
        cout << current_bit << " ";
    }
}

int main() {
    int number = 13;
    print_binary_representation(number);
    return 0;
}