class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        int temp = 0;

        for (int row = 0; row < 9; row++){
            res = validRow(board[row]);
            if (res == false) return res;
            for (int col = 0; col < 9; col++){
                if ((row % 3 == 0) && (col % 3 == 0)){
                    res = validBox(board, row, col);
                    if (res == false) return res;

                }
                if (temp < 9){
                    res = validCol(board, col);
                    if (res == false) return res;
                    temp++;
                }
            }
        }

        return res;

    }

    bool validRow(vector<char>& curr){
        unordered_set<char> seen;
        int temp = 0;
        bool res = true;
        for (char num : curr){
            if (num != '.'){
                seen.insert(num);
                temp++;
            }
        }

        if (temp != seen.size()){
            res = false;
            return res;
        }

        return res;
    }
    bool validCol(vector<vector<char>> board, int col){
        unordered_set<char> seen;
        int temp = 0;
        bool res = true;

        for (int tempRow = 0; tempRow < 9; tempRow++){
            if (board[tempRow][col] != '.'){
                seen.insert(board[tempRow][col]);
                temp++;
            }

        }
        
        if (temp != seen.size()){
            res = false;
            return res;
        }


        return res;
    }

    bool validBox(vector<vector<char>> board, int row, int col){
        unordered_set<char> seen;
        int temp = 0;
        bool res = true;

        for (int tempRow = row; tempRow < row + 3; tempRow++){
            for (int tempCol = col; tempCol < col + 3; tempCol++){
                if (board[tempRow][tempCol] != '.'){
                    seen.insert(board[tempRow][tempCol]);
                    temp++;
                }
            }
        }

        if (temp != seen.size()){
            res = false;
            return res;
        }

        return res;

    }
};
