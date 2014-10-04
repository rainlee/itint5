// ��ȷ���������б߽�i1 i2��Ȼ��i1-i2�Ӻ� ѹ����һ��
// ��һ��������������Ӷκͣ����Ӷ�O(m)
// ö��i1 i2�����Ӷ�O(n^2)
// [i1,i2]������� ����ͨ���е�ǰ׺������ʱ�临�Ӷ�O(n*m) �ռ临�Ӷ�O(n*m)
// �ܵ�ʱ�临�Ӷ�O(m*n^2)���ռ临�Ӷ�O(n)

// ��������ֶκ�
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

// ��2��ö�پ�������ϽǺ����½�
// ���������(i,j)Ϊ���½ǵľ���ĺ�sum[i][j]
// DP�� sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]
// sum{(i1,j1), (i2,j2)} = sum[i2][j2] - sum[i2][j1] - sum[i1][j2] + sum[i1][j1]
// ö�����Ͻ� ���½ǵ�ʱ�临�Ӷ���O(m^2 * n^2)
// �ռ临�Ӷ�O(n*m)