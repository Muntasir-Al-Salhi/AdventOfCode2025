#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::getline;
using std::stoi;

// Part 1
int main() {
    ifstream input("input.txt");
    int zeroCounter{0};
    int cur{50};
    string str;
    while (getline(input, str)) {
        int rot = stoi(str.substr(1));
        switch (str[0]) {
            case 'R':
                cur = (cur + rot) % 100;
                break;
            case 'L':
                cur = (cur - rot + 100) % 100;
                break;
        }
        if (cur == 0) {
            ++zeroCounter;
        }
    }
    std::cout << "Number of times at position 0: " << zeroCounter << '\n';

    
    return 0;
}