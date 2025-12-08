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

// Part 2
int main() {
    ifstream input("input.txt");
    string str;
    
    long long invalid_id_sum{0};
    
    while (getline(input, str, ',')) {
        array<long long, 2> range = getRange(str);
        for (long long i = range[1]; i >= range[0]; i--) {
            string id = to_string(i);
            int length = id.length();
            for (int n = length; n > 1; n--) {
                if (length % n == 0) {
                    int part_size{length/n};
                    string first_part{id.substr(0, part_size)};
                    bool is_invalid{true};
                    for (int j = part_size; j < length; j += part_size) {
                        if (id.substr(j, part_size) != first_part) {
                            is_invalid = false;
                            break;
                        }
                    }
                    if (is_invalid) {
                        invalid_id_sum += stoll(id);
                        break;
                    }
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
