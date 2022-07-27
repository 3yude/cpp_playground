#ifndef PARSE_HH
#define PARSE_HH

#include <iostream>
#include <string>
#include <vector>


std::vector<std::vector<int>> ParseToNumsNums(std::string);
std::vector<std::string> ParseToStrings(std::string);
void PrintStrings(std::vector<std::string>);

inline std::vector<std::vector<int>> ParseToNumsNums(std::string input) {
    std::vector<std::vector<int>> ret;
    //cout << input << endl;
    input = input.substr(1, input.size()-1);
    //cout << input << endl;
    
    std::vector<std::string> rows;
    while (input.find('[') != std::string::npos) {
        std::string s = input.substr(input.find('[') + 1, input.find(']') - input.find('[') - 1);
        //cout << s << endl; 
        rows.push_back(s);

        input = input.substr(input.find(']') + 1);
    }
    for (std::string s : rows) {
        std::string delimiter = ",";
        std::vector<int> row;
        while (s.find(delimiter) != std::string::npos) {
            std::string num = s.substr(0, s.find(delimiter));
            //cout << "num = " << num << endl;
            row.push_back(stoi(num));
            s.erase(0, s.find(delimiter) + delimiter.length());

        }
        //cout << "remain = " << s << endl;
        row.push_back(stoi(s));
        ret.push_back(row);
    }
    //for (string s : rows) {
    //    cout << s << endl;
    //}

    return ret;
}

inline std::vector<std::string> ParseToStrings(std::string input) {
    std::vector<std::string> ret;
    std::string s;
    int i = 0;
    while (i < input.size()) {
        if (input[i] == '"') {
            ++i;
            while (input[i] != '"') {
                s.push_back(input[i++]);
            }
            ret.push_back(s);
            s.clear();
        }
        i++;
    }

    return ret;
}

inline void PrintStrings(std::vector<std::string> input) {
    for (auto s : input) {
        std::cout << s << std::endl; 
    }
}
#endif


