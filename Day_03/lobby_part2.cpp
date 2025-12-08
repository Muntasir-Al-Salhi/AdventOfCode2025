#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::stoll;
using std::to_string;

// Part 2
int main() {
    ifstream input("input.txt");
    string bank;

    const int BATTERY_COUNT = 12;
    long long total_joltage{0};

    while (getline(input, bank)) {
        size_t bank_size{bank.length()};
        string available_batteries{bank};
        string active_batteries{};
        int battery_pos{0};
        for (int i = 0; i < BATTERY_COUNT; i++) {
            int next_best_battery{0};
            available_batteries = available_batteries.substr(battery_pos);
            int available_batteries_size = available_batteries.length();
            for (int j = 0; j < available_batteries_size - BATTERY_COUNT + i + 1; j++) {
                int battery_jolts{available_batteries[j] - '0'};
                if (battery_jolts > next_best_battery) {
                    next_best_battery = battery_jolts;
                    battery_pos = j + 1;
                } 
            }
            active_batteries += to_string(next_best_battery);
        }
        total_joltage += stoll(active_batteries);
    }
    cout << "Total output joltage: " << total_joltage << endl;
    
    return 0;
}
