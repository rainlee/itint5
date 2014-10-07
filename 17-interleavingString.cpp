// 动态规划
// dp[i][j]表示str3的前i+j个字符能否由str1的前i个 + str2的前j个组成
// 转移方程
//            / dp[i-1][j], if s1[i-i] == s3[i+j-1]
// dp[i][j] = 
//            \ dp[i][j-1], if s2[j-i] == s3[i+j-1]
bool isInterleaving_1(string &str1, string &str2, string &str3) {
    const int n1 = str1.size();
    const int n2 = str2.size();
    const int n3 = str3.size();
    if (n1 + n2 != n3)  return false;
    if (0 == n1) return (str2 == str3);
    if (0 == n2) return (str1 == str3);
    
    vector<vector<bool> > dp(n1+1, vector<bool>(n2+1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n1; ++i)
    {
        for (int j = 0; j <= n2; ++j)
        {
            if ((0 == i) && (0 == j))
                continue;
            if (0 == i)
                dp[i][j] = dp[i][j-1] && (str2[j-1] == str3[i+j-1]);
            else if (0 == j)
                dp[i][j] = dp[i-1][j] && (str1[i-1] == str3[i+j-1]);
            else
                dp[i][j] = (dp[i][j-1] && (str2[j-1] == str3[i+j-1])) || 
                           (dp[i-1][j] && (str1[i-1] == str3[i+j-1]));
        }
    }
    return dp[n1][n2];
}

// dp + 滚动数组
bool isInterleaving_2(string &str1, string &str2, string &str3) {
    const int n1 = str1.size();
    const int n2 = str2.size();
    const int n3 = str3.size();
    if (n1 + n2 != n3)  return false;
    if (0 == n1) return (str2 == str3);
    if (0 == n2) return (str1 == str3);
    
    vector<bool> dp(n2+1, false);
    dp[0] = true;
    for (int i = 0; i <= n1; ++i)
    {
        for (int j = 0; j <= n2; ++j)
        {
            if ((0 == i) && (0 == j))
                continue;
            if (0 == i)
                dp[j] = dp[j-1] && (str2[j-1] == str3[i+j-1]);
            else if (0 == j)
                dp[j] = dp[j] && (str1[i-1] == str3[i+j-1]);
            else
                dp[j] = (dp[j-1] && (str2[j-1] == str3[i+j-1])) || 
                        (dp[j] && (str1[i-1] == str3[i+j-1]));
        }
    }
    return dp[n2];
}

bool isInterleaving(string &str1, string &str2, string &str3) {
    return isInterleaving_2(str1, str2, str3);
}