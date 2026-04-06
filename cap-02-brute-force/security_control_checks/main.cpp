#include <iostream>

using namespace std;

struct SecurityCheck {
    int cost;
    int benefit;
    int false_negatives;
};

const int NUM_SECURITY_CHECKS = 8;

void solve(int P, int B, int F, SecurityCheck security_checks[NUM_SECURITY_CHECKS]) {
    int num_combinations = 1 << NUM_SECURITY_CHECKS;
    for (int combination = 0; combination < num_combinations; combination++) {
        int current_cost = 0;
        int current_benefit = 0;
        int current_false_negatives = 0;
        int current_solution[NUM_SECURITY_CHECKS];
        int current_solution_index = 0;
        for (int security_check = 0; security_check < NUM_SECURITY_CHECKS; security_check++) {
            if ((combination >> security_check) & 1) {
                current_cost += security_checks[security_check].cost;
                current_benefit += security_checks[security_check].benefit;
                current_false_negatives += security_checks[security_check].false_negatives;
                current_solution[current_solution_index++] = security_check + 1;
            }
        }
        if (current_cost <= P && current_benefit >= B && current_false_negatives <= F) {
            for (int j = 0; j < current_solution_index; j++) {
                cout << current_solution[j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    SecurityCheck security_checks[NUM_SECURITY_CHECKS] = {
        {35000,80,1},
        {24000,60,3},
        {30000,70,2},
        {27000,48,1},
        {10000,20,1},
        {7000,35,2},
        {6000,10,1},
        {40000,40,3}
    };
    int P=50000, B=100, F=3;
    solve(P, B, F, security_checks);
    return 0;
}