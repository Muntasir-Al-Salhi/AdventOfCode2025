#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::vector;
using std::string;
using std::getline;
using std::cout;
using std::endl;

int main() {
    ifstream input("input.txt");

    vector<string> layers;

    string line{};
    while (getline(input, line)) {
        layers.push_back(line);
    }

    int beam_splits{0};

    for (int i = 1; i < layers.size(); i++) {
        for (int j = 0; j < layers[0].size(); j++) {
            char above{layers[i - 1][j]};
            if (above == 'S' || above == '|') {
                char current{layers[i][j]};
                switch (current)
                {
                case '.':
                    layers[i][j] = '|';
                    break;
                case '^':
                    layers[i][j - 1] = '|'; // input does not have edge cases
                    layers[i][j + 1] = '|'; // no boundary check necessary
                    beam_splits++;
                    break;
                }
            }
        }
    }
    cout << "Number of beam splits: " << beam_splits << endl;
    
    return 0;
}
