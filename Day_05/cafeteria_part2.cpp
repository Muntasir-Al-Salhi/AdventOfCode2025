#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::sort;

struct range {
    long long floor;
    long long ceil;
};

range getRange(string str);
bool compareByFloor(const range range1, const range range2);

// Part 2
int main() {
    ifstream input("input.txt");
    vector<range> ranges;
    string line;

    while (getline(input, line)) {
        if (line.empty()) break;
        ranges.push_back(getRange(line));
    }

    sort(ranges.begin(), ranges.end(), compareByFloor);

    vector<range> disjointed_ranges;
    range current_range = ranges[0];

    for (int i = 1; i < ranges.size(); i++) {

        if (current_range.ceil < ranges[i].floor - 1) {
            disjointed_ranges.push_back(current_range);
            current_range = ranges[i];
        } else if (current_range.ceil < ranges[i].ceil) {
            current_range.ceil = ranges[i].ceil;
        }
    }

    disjointed_ranges.push_back(current_range);

    long long fresh_ingredient_id_count{0};

    for (range range : disjointed_ranges) {
        fresh_ingredient_id_count += range.ceil - range.floor + 1;
    }

    cout << "Number of ingredient id's considered to be fresh: " << fresh_ingredient_id_count << endl;
}

range getRange(const string str) {
    const int delimiter_index = str.find('-');
    if (delimiter_index == string::npos) {
        throw std::invalid_argument("invalid range (missing '-'): " + str);
    }
    const long long floor = stoll(str.substr(0, delimiter_index));
    const long long ceil = stoll(str.substr(delimiter_index + 1));
    return range{floor, ceil};
}

bool compareByFloor(const range range1, const range range2) {
    return range1.floor < range2.floor;
}