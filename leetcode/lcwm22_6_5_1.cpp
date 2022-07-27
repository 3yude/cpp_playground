#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

char firstUniqChar(string s); 

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Please enter content to be parsed." << endl;
    }
    string input(argv[1]);
    firstUniqChar(input);

    return 0;
}
char firstUniqChar(string s) {
    vector<int> counts(26, 0);
    vector<int> firstAppear(26, INT_MAX);

    for (int i = 0; i < s.size(); ++i) {
        if (counts[s[i] - 'a'] == 0) {
            firstAppear[s[i] - 'a'] = i;
        }
        ++counts[s[i] - 'a'];
    }

    for (int n : counts) {
        cout << " " << to_string(n);
    }
    cout << endl;

    for (int n : firstAppear) {
        cout << " " << to_string(n) << endl;;
    }

    int ans = 0;
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i] == 1 && firstAppear[ans] > firstAppear[i]) {
            cout << "ans=" << to_string(ans) << " firstAppear[i]=" << to_string(firstAppear[i]) << endl;
            ans = i;
        }
    }
    cout << to_string(ans) << endl;
    char ret = 'a' + ans;
    return ans == INT_MAX ? ' ' : ret;
}


