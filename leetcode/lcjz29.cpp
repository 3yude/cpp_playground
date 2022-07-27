#include <cstddef>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<vector<int>> parseInput(string);
vector<int> spiralOrder(vector<vector<int>>& matrix);

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
    spiralOrder(in);

    return 0;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = -1;
        int bottom = matrix.size() ;
        int left = -1;
        int right = matrix[0].size();

        int direction = 0;
        int x = 0;
        int y = -1;

        vector<int> ret;

        while (top - bottom != 1 && right - left != 1) {
            direction &= 3;
            cout << " direction = " << direction;
            cout << " top = " << top;
            cout << " left = " << left;
            cout << " right = " << right;
            cout << " bottom = " << bottom;
            cout << endl;
            switch (direction) {
                case 0 :
                while (y + 1 != right) {
                    ret.push_back(matrix[x][++y]);
                }
                top += 1;
                break;

                case 1 :
                while (x + 1 != bottom) {
                    ret.push_back(matrix[++x][y]);
                }
                right -= 1;
                break;

                case 2 : 
                while (y - 1 != left) {
                    ret.push_back(matrix[x][--y]);
                }
                bottom -= 1;
                break;

                case 3 :
                while (x - 1 != top) {
                    ret.push_back(matrix[--x][y]);
                }
                left += 1;
                break;

                default: ;

            }
            ++direction;
        }

        return ret;
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




