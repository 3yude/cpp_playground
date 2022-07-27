#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include "parse.hh"

using namespace std;

class Solution {
public:
    void PrintString(vector<pair<string, int>> &input) {
        for (auto in : input) {
            cout << in.first << endl;
        }
    }
    static bool mycomp(pair<string, int> a, pair<string, int> b) {
        return a.first < b.first;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ret;
        unordered_map<int, vector<pair<string, int>>> query_map;
        for (vector<int> &query : queries) {
            if (!query_map.count(query[1])) {
                vector<pair<string, int>> subnum;
                for (int i = 0; i < nums.size(); ++i) {
                    string &s = nums[i];
                    subnum.push_back({s.substr(s.size() - query[1]), i});
                }
                sort(subnum.begin(), subnum.end(), mycomp);
                query_map[query[1]] = subnum;
                PrintString(subnum);
            }

            ret.push_back(query_map[query[1]][query[0]-1].second);
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    string line1;
    string line2;
    getline(cin, line1);
    getline(cin, line2);
    //string input1(argv[1]);
    //string input2(argv[2]);
        
    //cout << line1 << endl;
    //cout << line2 << endl;
    vector<string> in1 = ParseToStrings(line1);
    vector<vector<int>> in2 = ParseToNumsNums(line2);

    Solution solution;
    solution.smallestTrimmedNumbers(in1, in2);
    return 0;
}

