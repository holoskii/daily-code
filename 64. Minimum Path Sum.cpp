//https://leetcode.com/problems/minimum-path-sum/
int minPathSum(vector<vector<int>> a) {
        const int n = a.size();
        const int m = a.at(0).size();
        if(n == 0 || m == 0) return 0;

        int d[n][m];
        d[0][0] = a[0][0];

        for(int i = 1; i < n; i++)
            d[i][0] = d[i - 1][0] + a[i][0];

        for(int j = 1; j < m; j++)
            d[0][j] = d[0][j - 1] + a[0][j];

        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                d[i][j] = min(d[i - 1][j], d[i][j - 1]) + a[i][j];

        return d[n - 1][m - 1];
    }
