class Solution {
public:
    bool isTheSameInSubBox(int kx, int ky, int jx, int jy) {
        
        if (kx / 3 == jx / 3 && 
            ky / 3 == jy / 3) {
            return true;
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        using Coord = pair<int, int>;
        vector<vector<Coord>> numbersAndCoords(10);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (isdigit(board[i][j])) {
                    int digit = board[i][j] - '0';
                    // cout << "digit: " << digit << endl;
                    numbersAndCoords[digit].emplace_back(Coord{i,j});
                }
            }
        }

        for (int i = 1; i < 10; ++i) {
            // cout << "num: " << i << endl;
            const auto & vec = numbersAndCoords[i];
            for (int k = 0; k < vec.size(); ++k) {
                for (int j = k + 1; j < vec.size(); ++j) {
                    const auto & [kx, ky] = vec[k];
                    const auto & [jx, jy] = vec[j];
                    if (kx == jx || ky == jy) {
                        // cout << "same row/column k:[" << kx << ", " << ky <<
                            //  "], j: [" << jx << ", " << jy << "]\n";
                        // row or column consists the same value
                        return false;
                    }
                    if (isTheSameInSubBox(kx, ky, jx, jy)) {
                        // cout << "same sub box k:[" << kx << ", " << ky <<
                            //  "], j: [" << jx << ", " << jy << "]\n";
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
