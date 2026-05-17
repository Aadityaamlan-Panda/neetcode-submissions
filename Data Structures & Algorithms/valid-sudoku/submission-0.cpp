class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedRows[9][9] = {0};
        int usedCols[9][9] = {0};
        int usedSG[9][9] = {0};
        for (int i=0; i<board.size(); i++)
        {
            for (int j=0; j<board[i].size(); j++)
            {
                if (board[i][j]!='.')
                {
                    int nums = board[i][j] - '0' -1;
                    int sgidx = (i/3)*3 + j/3;
                    if (usedRows[i][nums] || usedCols[j][nums] || usedSG[sgidx][nums])
                    return false;
                    usedRows[i][nums] = usedCols[j][nums] = usedSG[sgidx][nums] = 1;
                }
            }
        }
        return true;
    }
};
