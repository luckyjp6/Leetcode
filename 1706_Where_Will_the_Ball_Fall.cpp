class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result;
        enum status {down, left, right};
        for (int ball = 0; ball < n; ball++) {
            int now_m = 0, now_n = ball;
            status s = down;
            while (now_m < m) {
                if (grid[now_m][now_n] == 1) {
                    switch (s) {
                        case down:
                            s = right;
                            now_n++;
                            break;
                        case right:
                            s = down;
                            now_m++;
                            break;
                        case left:
                            now_n = -1; // stuck
                            break;
                    }
                } else {
                    switch (s) {
                        case down:
                            s = left;
                            now_n--;
                            break;
                        case right:
                            now_n = -1; // stuck
                            break;
                        case left:
                            s = down;
                            now_m++;
                            break;
                    }
                }
                if (now_n >= n || now_n < 0) {
                    result.push_back(-1);
                    break;
                }
            }
            if (now_m == m && now_n >= 0 && now_n < n) {
                result.push_back(now_n);
            }
        }
        return result;
    }
};