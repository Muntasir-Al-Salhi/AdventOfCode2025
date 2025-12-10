#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::array;

array<long long, 2> getRange(string str);

// Part 1
int main() {
    ifstream input("input.txt");
    vector<array<long long, 2>> ranges;
    string line;
    while (getline(input, line)) {
        if (line.empty()) break;
        ranges.push_back(getRange(line));
    }

    int fresh_ingredients{0};

    while (getline(input, line)) {
        long long id{stoll(line)};
        for (array<long long, 2> range : ranges) {
            if (range[0] < id && id < range[1]) {
                fresh_ingredients++;
                break;
            }
        }
    }
    cout << "Number of fresh ingredients: " << fresh_ingredients << endl;

    return 0;
}

array<long long, 2> getRange(const string str) {
    int delimiter_index = str.find('-');
    if (delimiter_index == string::npos) {
        throw std::invalid_argument("invalid range (missing '-'): " + str);
    }
    long long floor = stoll(str.substr(0, delimiter_index));
    long long ceil = stoll(str.substr(delimiter_index + 1));
    array<long long, 2> range{floor, ceil};
    return range;
}
