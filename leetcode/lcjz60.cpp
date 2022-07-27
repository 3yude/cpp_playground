#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<double> dicesProbability(int n) {

    unordered_map<int, int> ans;

    for (int i = 1; i <= 6; ++i) {
        ans[i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        unordered_map<int, int> newans;
        for (auto &element : ans) {
            for (int j = 1; j <= 6; ++j) {
                newans[element.first + j] += element.second;
            }
        }
        ans = newans;
    }

    long long samplespace = 0;
    vector<int> space(ans.size());
    int i = 0;
    for (auto &element : ans) {
        cout << "element.first = " << element.first << " element.second = " << element.second << endl;
        samplespace += element.second;
        space[i++] = element.first;
    }

    cout << "samplespace = " << samplespace << endl;
    sort(space.begin(), space.end());
    for (auto num : space) {
        cout << "num = " << num << endl;
    }
    vector<double> ret(ans.size());
    for (i = 0; i < space.size(); ++i) {
        space[i] = ans[space[i]]/(double)samplespace;
    }

    return ret;

}
int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Please enter content to be parsed." << endl;
    }
    string input(argv[1]);

    dicesProbability(2);

    return 0;
}

