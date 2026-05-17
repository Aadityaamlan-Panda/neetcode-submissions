class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>col[9];
        unordered_set<char>row[9];
        unordered_set<char>boxes[9];
        for(int r=0;r<9;r++){
            for (int c=0;c<9;c++){
                char current =board[r][c];
                if (current=='.') continue;
                int box = (r/3)*3 + c/3;
                if (col[c].count(current) || row[r].count(current) || boxes[box].count(current))
                return false;

                col[c].insert(current);
                row[r].insert(current);
                boxes[box].insert(current);
            }
        }
        return true;
    }
};
