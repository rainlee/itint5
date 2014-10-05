// DP
// dp[i][j]表示走到(i,j)的路径数
// dp[i][j] = (blocked[i-1][j] ? 0 : dp[i-1][j]) + (blocked[i][j-1] ? 0 : dp[i][j-1])
int totalPath_1(vector<vector<bool> > &blocked) {
    if (blocked.empty() || blocked[0].empty() || blocked[0][0])
        return 0;
    const int n = blocked.size();
    const int m = blocked[0].size();
    vector<vector<int> > dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((0 == i) && (0 == j))
                continue;
            dp[i][j] = blocked[i][j] ? 0 : 
                       (((i > 0) ? (blocked[i-1][j] ? 0 : dp[i-1][j]) : 0) + 
                        ((j > 0) ? (blocked[i][j-1] ? 0 : dp[i][j-1]) : 0));
        }
    }
    return dp[n-1][m-1];
}

// 滚动数组优化空间
int totalPath_2(vector<vector<bool> > &blocked) {
    if (blocked.empty() || blocked[0].empty() || blocked[0][0])
        return 0;
    const int n = blocked.size();
    const int m = blocked[0].size();
    vector<int> dp(m, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((0 == i) && (0 == j))
                continue;
            dp[j] = blocked[i][j] ? 0 : 
                    (((i > 0) ? (blocked[i-1][j] ? 0 : dp[j]) : 0) + 
                     ((j > 0) ? (blocked[i][j-1] ? 0 : dp[j-1]) : 0));
        }
    }
    return dp[m-1];
}

int totalPath(vector<vector<bool> > &blocked) {
    return totalPath_2(blocked);
}