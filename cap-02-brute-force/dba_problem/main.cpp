#include <iostream>
#include <cmath>

using namespace std;

const int TOTAL_TABLES = 6;
const int TOTAL_DISKS = 3;

void copy(int N, int source[], int destination[]) {
    for (int i = 0; i < N; i++) {
        destination[i] = source[i];
    }
}

void solve(int tables[TOTAL_TABLES], int disks[TOTAL_DISKS]) {
    int num_combinations = pow(TOTAL_DISKS, TOTAL_TABLES);
    int max_iops = -1;
    int best_solution[TOTAL_TABLES];
    for (int combination = 0; combination < num_combinations; combination++) {
        int cur_combination = combination;
        int cur_disks_iops[TOTAL_DISKS];
        copy(TOTAL_DISKS, disks,cur_disks_iops);
        bool is_valid = true;
        int cur_solution[TOTAL_TABLES];
        for (int table = 0; table < TOTAL_TABLES; table++) {
            int cur_disk = cur_combination % TOTAL_DISKS;
            cur_combination = cur_combination / TOTAL_DISKS;

            cur_disks_iops[cur_disk] -= tables[table];
            cur_solution[table] = cur_disk;

            if (cur_disks_iops[cur_disk] < 0) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            int cur_min_iops = cur_disks_iops[0];
            for (int disk = 0; disk < TOTAL_DISKS; disk++) {
                if (cur_disks_iops[disk] < cur_min_iops) {
                    cur_min_iops = cur_disks_iops[disk];
                }
            }
            if (cur_min_iops > max_iops ) {
                max_iops = cur_min_iops;
                copy(TOTAL_TABLES, cur_solution, best_solution);
            }
        }
    }

    cout << max_iops << endl;
    for (int disk = 0; disk < TOTAL_DISKS; disk++) {
        cout << "Disco: " << disk + 1 << endl;
        for (int table = 0; table < TOTAL_TABLES; table++) {
            if (best_solution[table] == disk) {
                cout << table + 1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int tables[TOTAL_TABLES] = {150, 100, 80, 50, 120, 10};
    int disks[TOTAL_DISKS] = {250, 200, 200};
    solve(tables, disks);
    return 0;
}