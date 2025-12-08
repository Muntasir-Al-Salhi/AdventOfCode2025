#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::stoi;
using std::to_string;

// Part 1
int main() {
    ifstream input("input.txt");
    string bank;

    int total_joltage{0};
    
    while (getline(input, bank)) {
        size_t bank_size{bank.length()};
        int best_battery{0};
        int best_battery_pos{-1};
        for (int i = 0; i < bank_size - 1; i++) {
            int battery_jolts{bank[i] - '0'};
            if (battery_jolts > best_battery) {
                best_battery = battery_jolts;
                best_battery_pos = i;
            }
        }
        int best_second_battery{0};
        for (int i = best_battery_pos + 1; i < bank_size; i++) {
            int battery_jolts{bank[i] - '0'};
            if (battery_jolts > best_second_battery) {
                best_second_battery = battery_jolts;
            }
        }
        total_joltage += stoi(to_string(best_battery) + to_string(best_second_battery));
    }
    cout << "Total output joltage: " << total_joltage << endl;    

    return 0;
}
