#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::getline;
using std::stoi;

// Part 2
int main() {
    ifstream input("input.txt");
    int zeroCounter{0};
    int cur{50};
    string str;
    while (getline(input, str)) {
        int rot = stoi(str.substr(1));
        while (rot != 0) {
            switch (str[0])
            {
            case 'R':
                cur += 1;
                if (cur == 100)
                cur = 0;
                break;
            case 'L':
                cur -= 1;
                if (cur == -1) {
                    cur = 99;
                }
                break;
            }
            rot--;
            if (cur == 0) {
                ++zeroCounter;
            }
        }
    }
    std::cout << "Number of times at position 0: " << zeroCounter << '\n';

    
    return 0;
}
