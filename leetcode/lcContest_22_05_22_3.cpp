#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> parseInput(string);
int minimumLines(vector<vector<int>>& stockPrices); 

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Please enter content to be parsed." << endl;
    }
    string input(argv[1]);
        
    vector<vector<int>> in = parseInput(input);
    //for (vector<int> nums : in) {
    //    cout << "[";
    //    for (int num : nums) {
    //        cout << to_string(num) << ",";
    //    }
    //    cout << "]" << endl;
    //}
    //
    
    minimumLines(in);


    return 0;
}

void printNums(vector<vector<int>> &in) {
    for (vector<int> nums : in) {
        cout << "[";
        for (int num : nums) {
            cout << to_string(num) << ",";
        }
        cout << "]" << endl;
    }
}
static bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0] < b[0]) return true;
    return false;
}
bool compareSlope(long long aNumerator, long long aDenominator, long long bNumerator, long long bDenominator) {
    if (bNumerator * aDenominator == aNumerator * bDenominator) return true;

    return false;
}
int minimumLines(vector<vector<int>>& stockPrices) {
    if (stockPrices.size() < 2) return 0;

    sort(stockPrices.begin(), stockPrices.end(), comp);
    printNums(stockPrices);

    int numerator = stockPrices[1][1] - stockPrices[0][1];
    int denominator = stockPrices[1][0] - stockPrices[0][0];
    int amount = 1;

    for (int i = 2; i < stockPrices.size(); ++i) {
        if (!compareSlope(numerator, denominator, stockPrices[i][1] - stockPrices[i-1][1], stockPrices[i][0] - stockPrices[i-1][0])) {
            cout << "i=" << to_string(i) << endl;
            cout << "numerator=" << to_string(numerator);
            cout << " denominator=" << to_string(denominator) << endl;
            cout << "stockPrices[i][1] - stockPrices[i-1][1] = " << to_string(stockPrices[i][1] - stockPrices[i-1][1]);
            cout << " stockPrices[i][0] - stockPrices[i-1][0] = " << to_string(stockPrices[i][0] - stockPrices[i-1][0]) << endl;
            ++amount;
            numerator = stockPrices[i][1] - stockPrices[i-1][1];
            denominator = stockPrices[i][0] - stockPrices[i-1][0];
        }
    }

    return amount;
}
vector<vector<int>> parseInput(string input) {
    vector<vector<int>> ret;
    //cout << input << endl;
    input = input.substr(1, input.size()-1);
    //cout << input << endl;

    vector<string> rows;
    while (input.find('[') != string::npos) {
        string s = input.substr(input.find('[') + 1, input.find(']') - input.find('[') - 1);
        //cout << s << endl; 
        rows.push_back(s);

        input = input.substr(input.find(']') + 1);
    }
    for (string s : rows) {
        string delimiter = ",";
        vector<int> row;
        while (s.find(delimiter) != string::npos) {
            string num = s.substr(0, s.find(delimiter));
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




