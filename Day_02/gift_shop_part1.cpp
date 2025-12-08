#include <string>
#include <fstream>
#include <array>
#include <iostream>

using std::string;
using std::ifstream;
using std::array;
using std::to_string;
using std::stoll;
using std::cout;
using std::endl;

array<long long, 2> getRange(string str);

// Part 1
int main() {
    ifstream input("input.txt");
    string str;
    
    long long invalid_id_sum{0};
    
    while (getline(input, str, ',')) {
        array<long long, 2> range = getRange(str);
        for (long long i = range[1]; i >= range[0]; i--) {
            string id = to_string(i);
            int length = id.length();
            if (length % 2 == 0) {
                string first_half{id.substr(0, length / 2)};
                string second_half{id.substr(length/2)};
                if (first_half == second_half) {
                    invalid_id_sum += stoll(id);
                }
            }
        }
    }

    cout << "Sum of invalid IDs: " << invalid_id_sum << endl;

    return 0;
};

array<long long, 2> getRange(string str) {
    int delimiter_index = str.find('-');
    if (delimiter_index == string::npos) {
        throw std::invalid_argument("invalid range (missing '-'): " + str);
    }
    long long floor = stoll(str.substr(0, delimiter_index));
    long long ceil = stoll(str.substr(delimiter_index + 1));
    array<long long, 2> range{floor, ceil};
    return range;
}