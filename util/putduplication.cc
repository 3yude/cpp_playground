#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include "../lib/parse.hh"

using namespace std;

int main() {
    unordered_set<string> input;
    vector<string> ouput;

    string file1{"putduplication_in1.data"};
    string file2{"putduplication_in2.data"};

    fstream fstrm;
    ofstream out;
    string s;

    fstrm.open(file1);
    while (fstrm >> s) {
        if (!s.empty()) {
            input.insert(s);
        }
        s.clear();
    }
    fstrm.close();

    fstrm.open(file2);
    while (fstrm >> s) {
        if (input.count(s) > 0) {
            ouput.push_back(s);
        }
        s.clear();
    }
    fstrm.close();

    out.open("putduplication_out.data");
    if (out) {
        for (auto line : ouput) {
            out << line << "\n";
            cout << "1" << endl;
        }
        fstrm << flush;
    }
    out.close();
    //PrintStrings(ouput);

    return 0;
}

