#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

bool exist(vector<vector<char>>& board, string word);

int main(int argc, char** argv) {
    string input("ABCCED");
    vector<vector<char>> board({{'A','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'}});

    exist(board, input);
    return 0;
}
    void dfs(const vector<vector<char>>& board, const string &word, vector<vector<bool>>& visited, int y, int x, int index, bool &ans)
    {
        cout <<  "y=" << y << " x=" << x << " index= " << index << " ans=" << ans << endl;
        if (word[index] != board[y][x]) {
            return;
        }
        if (index == word.size() - 1) {
            ans = true;
            return;
        }


        visited[y][x] = true;
        
        if (y < board.size()-1 && visited[y+1][x] != true) {
            dfs(board, word, visited, y+1, x, index+1, ans);
        }
        if (y > 0 && visited[y-1][x] != true) {
            dfs(board, word, visited, y-1, x, index+1, ans);
        }
        if (x < board[0].size() - 1 && visited[y][x+1] != true) {
            dfs(board, word, visited, y, x+1, index+1, ans);
        }
        if (x > 0 && visited[y][x] != true) {
            dfs(board, word, visited, y, x-1, index+1, ans);
        }

        visited[y][x] = false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ret = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, word, visited, i, j, 0, ret);
            }
        }

        return ret;
    }
