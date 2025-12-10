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
using std::sregex_iterator;
using std::count;
using std::to_string;

struct problem {
    vector<int> terms;
    char operation;
};

vector<string> split_string_before_non_space_after_space(const string& str);

// Part 2
int main() {
    ifstream input("input.txt");
    
    vector<string> lines;
    
    string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }

    string operations_line{lines.back()};
    vector<string> operation_tokens = split_string_before_non_space_after_space(operations_line);
    vector<char> operations;

    vector<int> number_lengths;
    for (const string str : operation_tokens) {
        auto number_length{count(str.begin(), str.end(), ' ')};
        number_lengths.push_back(static_cast<int>(number_length));
        operations.push_back(str[0]);
    }
    number_lengths.back()++;

    vector<vector<string>> number_line;
    number_line.reserve(operations.size());

    for (int i = 0; i < lines.size() - 1; i++) {
        int last_pos{0};
        vector<string> number;
        for (int j = 0; j < number_lengths.size(); j++) {
            number.push_back(lines[i].substr(last_pos, number_lengths[j]));
            last_pos += number_lengths[j] + 1;
        }
        number_line.push_back(number);
    }

    vector<problem> problems;

    for (int j = 0; j < number_line[0].size(); j++) {
        problem problem;
        problem.operation = operations[j];
        for (int k = number_lengths[j] - 1; k >= 0; k--) {
            string number{};
            for (int l = 0; l < number_line.size(); l++) {
                if (number_line[l][j][k] == ' ') continue;
                int digit;
                digit = number_line[l][j][k] - '0';
                number += to_string(digit);
            }
            if (!number.empty()) {
                problem.terms.push_back(stoi(number));
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

vector<string> split_string_before_non_space_after_space(const string& str) {
    regex regex("\\S\\s+");
    
    vector<string> result;
    sregex_iterator iterator(str.begin(), str.end(), regex);
    sregex_iterator end;

    for (; iterator != end; ++iterator) {
        result.push_back(iterator->str());
    }

    return result;
}
