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

    vector<vector<long long>> layers;

    string line{};
    while (getline(input, line)) {
        vector<long long> layer;
        for (char c : line) {
            if (c == '.') layer.push_back(0);
            else if (c == '^') layer.push_back(-1);
            else if (c == 'S')layer.push_back(1);
        }
        layers.push_back(layer);
    }

    for (int i = 1; i < layers.size(); i++) {
        for (int j = 0; j < layers[0].size(); j++) {
            long long above{layers[i - 1][j]};
            if (above <= 0) continue;
            long long current{layers[i][j]};
            if (current < 0) {
                layers[i][j - 1] += above;
                layers[i][j + 1] += above;
            } else {
                layers[i][j] += above;
            }
        }
    }

    long long timelines{0};
    for (long long num : layers[layers.size() - 1]) {
        timelines += num;
    }

    cout << "Number of timelines: " << timelines << endl;
    
    return 0;
}
