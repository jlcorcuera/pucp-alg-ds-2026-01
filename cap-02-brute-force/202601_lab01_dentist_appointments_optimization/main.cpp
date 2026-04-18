#include <iostream>
#include <cmath>

using namespace std;

struct Tooth {
    int id;
    int total_time;
    int total_profit;
};

int main() {
    Tooth teeth[8] = {
        {1, 3 * 5, 3 * 20},  // 15 min, 60 soles
        {2, 1 * 5, 1 * 20},  // 5 min, 20 soles
        {3, 0 * 7, 0 * 30},  // 0 min, 0 soles (Skip)
        {4, 1 * 10, 1 * 35},  // 5 min, 20 soles
        {5, 2 * 10, 2 * 35}, // 20 min, 70 soles
        {6, 1 * 12, 1 * 42}, // 12 min, 42 soles
        {7, 2 * 12, 2 * 42}, // 24 min, 84 soles
        {8, 3 * 12, 3 * 42}  // 36 min, 126 soles
    };

    int max_profit = 0;
    int best_plan[8] = {0};

    long long num_combinations = pow(4, 8);

    for (long long i = 0; i < num_combinations; i++) {
        int current_plan[8];
        long long temp = i;

        int time_a1 = 0, time_a2 = 0, time_a3 = 0;
        int current_profit = 0;
        bool valido = true;

        for (int j = 0; j < 8; j++) {
            current_plan[j] = temp % 4;
            temp /= 4;

            if (current_plan[j] == 3) {
                continue;
            }

            if (current_plan[j] == 0) {
                time_a1 += teeth[j].total_time;
            } else if (current_plan[j] == 1) {
                time_a2 += teeth[j].total_time;
            } else if (current_plan[j] == 2) {
                time_a3 += teeth[j].total_time;
            }
            current_profit += teeth[j].total_profit;
        }

        if (time_a1 > 60 || time_a2 > 45 || time_a3 > 50) {
            continue;
        }

        if (valido && current_profit > max_profit) {
            max_profit = current_profit;
            for (int j = 0; j < 8; j++) best_plan[j] = current_plan[j];
        }
    }

    for (int appointment = 1; appointment <= 3; appointment++) {
        for (int j = 0; j < 8; j++) {
            if (best_plan[j] == appointment - 1) {
                cout << "Cita: " << appointment << " Diente: " << teeth[j].id << endl;
            }
        }
    }
    cout << "La ganancia maxima es: " << max_profit << endl;

    return 0;
}