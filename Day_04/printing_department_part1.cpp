#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

// Part 1
int main() {
    ifstream input("input.txt");
    vector<vector<int>> room;
    
    string line;
    while (getline(input, line)) {
        vector<int> row;
        row.reserve(line.length());
        for (int i = 0; i < line.length(); i++) {
            row.push_back(line[i] == '@' ? 1 : 0);
        }
        room.push_back(row);
    }

    const size_t row_count{room.size()};
    const size_t col_count{room[0].size()};

    int accessible_papers{0};

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            if (room[i][j] != 1) continue;
            int adjacent_papers{0};
            const bool first_row{i == 0};
            const bool first_col{j == 0};
            const bool last_row{i == row_count - 1};
            const bool last_col{j == col_count - 1};
            if (!first_row) {
                adjacent_papers += room[i-1][j];
                if (!first_col) adjacent_papers += room[i-1][j-1];
                if (!last_col) adjacent_papers += room[i-1][j+1];
            }
            if (!last_row) {
                adjacent_papers += room[i+1][j];
                if (!first_col) adjacent_papers += room[i+1][j-1];
                if (!last_col) adjacent_papers += room[i+1][j+1];
            }
            if (!first_col) adjacent_papers += room[i][j-1];
            if (!last_col) adjacent_papers += room[i][j+1];

            if (adjacent_papers < 4) accessible_papers++;
        }
    }
    cout << "Number of accessible papers: " << accessible_papers << endl;

    return 0;
}
