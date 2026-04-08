#include <unordered_map>
#include <array>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool boxes[4][4][10] = {false};
        bool columns[10][10] = {false};
        bool rows[10][10] = {false};

        for (int row = 0; row < 9; ++row) {

            int boxRow = row / 3;

            for (int column = 0; column < 9; ++column) {

                int boxColumn = column / 3;

                char entry = board[row][column];

                if (entry == '.') {
                    continue;
                }

                int digit = entry - '0';

                if (rows[row][digit] or columns[column][digit] or boxes[boxRow][boxColumn][digit]) {
                    
                    return false;
                }

                boxes[boxRow][boxColumn][digit] = true;
                columns[column][digit] = true;
                rows[row][digit] = true;

            }

        }

        return true;
    }
};
