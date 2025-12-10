#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stoi;
using std::vector;
using std::regex;
using std::sregex_token_iterator;

struct problem {
    vector<int> terms;
    char operation;
};

string trim_start(const string& str);

// Part 1
int main() {
    ifstream input("input.txt");
    
    vector<vector<string>> lines;
    
    string line;
    while (getline(input, line)) {
        line = trim_start(line);
        regex regex (" +");
        sregex_token_iterator iterator(line.begin(), line.end(), regex, -1);
        sregex_token_iterator end;
        vector<string> space_separated(iterator, end);
        lines.push_back(space_separated);
    }

    vector<problem> problems;

    for (size_t i = 0; i < lines[0].size(); i++) {
        problem problem;
        for (size_t j = 0; j < lines.size(); j++) {
            try {
                int number{stoi(lines[j][i])};
                problem.terms.push_back(number);
            } catch (std::invalid_argument) {
                problem.operation = lines[j][i][0];
            }
        }
        problems.push_back(problem);
    }

    long long total{0};

    for (problem problem : problems) {
        long long result{1};
        switch (problem.operation)
        {
        case '+':
            for (long long term : problem.terms) result += term;
            break;
        case '*':
            for (long long term : problem.terms) result *= term;
            break;
        }
        if (problem.operation == '+') result -= 1;
        total += result;
    }
    cout << "Sum of all results: " << total << endl;    

    return 0;
}

string trim_start(const string& str) {
    string::const_iterator start = std::find_if_not(str.begin(), str.end(), ::isspace);
    return string(start, str.end());
}
