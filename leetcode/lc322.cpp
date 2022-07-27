#include <iostream>


using namespace std;
class Solution {
public:
    void backtracking(vector<int>& coins, int amount, vector<int>& ans, int index, int level) {
        if (amount < 0) return;
        if (amount == 0) ans.push_back(level);
        for (int i = index; i < coins.size(); ++i) {
            backtracking(coins, amount-coins[i], ans, i, level+1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> ans;
        backtracking(coins, amount, ans, 0, 0);

        if (ans.size() == 0) return -1;
        int ret = INT_MAX;
        for (int n : ans) {
            ret = min(ret, n);
        }
        // return ans[ans.size() - 1];
        return ret;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        
        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
