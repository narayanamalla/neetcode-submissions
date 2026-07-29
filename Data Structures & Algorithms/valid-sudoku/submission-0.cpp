class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to keep track of the numbers seen in each row, column, and 3x3 box.
        // There are 9 rows, 9 columns, and 9 boxes. Each can hold digits 1-9 (mapped to index 0-8).
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    
                    int val = board[r][c] - '1';
                    
                    
                    int box_index = (r / 3) * 3 + (c / 3);
                    
                   
                    if (rows[r][val] || cols[c][val] || boxes[box_index][val]) {
                        return false;
                    }
                    
                   
                    rows[r][val] = true;
                    cols[c][val] = true;
                    boxes[box_index][val] = true;
                }
            }
        }
        
        return true;
    }
};