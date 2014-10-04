// 先确定上下两行边界i1 i2，然后将i1-i2加和 压缩到一行
// 再一行上求最大连续子段和，复杂度O(m)
// 枚举i1 i2，复杂度O(n^2)
// [i1,i2]的列求和 可以通过列的前缀数组求差，时间复杂度O(n*m) 空间复杂度O(n*m)
// 总的时间复杂度O(m*n^2)，空间复杂度O(n)

// 最大连续字段和
int maxConsSum(vector<int> &a) {
    if (a.empty())
        return 0;
    int maxs = 0;
    int sum = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        sum = max(sum + a[i], 0);
        maxs = max(maxs, sum);
    }
    return maxs;
}
int maxRectSum(vector<vector<int> > &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    
    const int n = matrix.size();
    const int m = matrix[0].size();
    
    vector<vector<int> > vsum(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            vsum[i][j] = matrix[i][j] + ((i > 0) ? vsum[i-1][j] : 0);
    
    vector<int> vsum12(m, 0);
    int maxs = 0;
    for (int i1 = 0; i1 < n; ++i1)
    {
        for (int i2 = i1; i2 < n; ++i2)
        {
            for (int j = 0; j < m; ++j)
                vsum12[j] = vsum[i2][j] - ((i1 > 0) ? vsum[i1-1][j] : 0);
            
            maxs = max(maxs, maxConsSum(vsum12));
        }
    }
    return maxs;
}

// 法2：枚举矩阵的左上角和右下角
// 可以求出以(i,j)为右下角的矩阵的和sum[i][j]
// DP求 sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]
// sum{(i1,j1), (i2,j2)} = sum[i2][j2] - sum[i2][j1] - sum[i1][j2] + sum[i1][j1]
// 枚举左上角 右下角的时间复杂度是O(m^2 * n^2)
// 空间复杂度O(n*m)