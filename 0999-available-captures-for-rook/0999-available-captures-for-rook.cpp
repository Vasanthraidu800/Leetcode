class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }

        int ans = 0;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for (auto [dx, dy] : dir) {
            int x = r + dx;
            int y = c + dy;

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 'B') break;

                if (board[x][y] == 'p') {
                    ans++;
                    break;
                }

                x += dx;
                y += dy;
            }
        }

        return ans;
    }
};