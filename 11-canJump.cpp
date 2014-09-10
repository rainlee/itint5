// DP �������ÿһ���Ƿ��ܵ���
// ʹ(x,y)�����Ͻ� (x2,y2)�����½ǣ����Խ���ת�������Խ���
/*
void preProcess(int &x, int &y, int &x2, int &y2)
{
    if ((x < 0) || (x2 < 0))
    {
        int minx = min(x, x2);  // ƫ�Ƶ�����
        int k = -minx;
        x += k;
        x2 += k;
    }
    if ((y < 0) || (y2 < 0))
    {
        int miny = min(y, y2);  // ƫ�Ƶ�����
        int k = -miny;
        y += k;
        y2 += k;
    }
    if (x == x2)
    {
        if (y > y2)
            swap(y, y2);
    }
    else if (y == y2)
    {
        if (x > x2)
            swap(x, x2);
    }
    else if ((y2 - y) * (x2 - x) > 0)  // ���Խ���
    {
        if (x > x2)
        {
            swap(x, x2);
            swap(y, y2);
        }
    }
    else  // ���Խ���
    {
        int maxx = max(x, x2);
        int minx = min(y, y2);
        x = minx;
        x2 = maxx;
        
        int maxy = max(y, y2);
        int miny = min(y, y2);
        y = miny;
        y2 = maxy;
    }
    return;
}
const int directions[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
bool canJump(int x, int y, int x2, int y2) {
    preProcess(x, y, x2, y2);
    
    const int n = x2 - x + 1;
    const int m = y2 - y + 1;
    vector<vector<bool> > dp(n, vector<bool>(m, false));
    
    dp[0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!dp[i][j])
                continue;
            for (int k = 0; k < 8; ++k)
            {
                int row = i + x + directions[k][0];
                int col = j + y + directions[k][1];
                if ((row >= x) && (row <= x2) && (col >= y) && (col <= y2))
                    dp[row-x][col-y] = true;
                if ((row == x2) && (col == y2))
                    break;
            }
        }
    }
    return dp[n-1][m-1];
}
*/

// ��1 �����ˡ���
// �����������޴��������ܹ�������һλ�á�
// Ϊ��֤��������ۣ������Ȼ�ͼ֤�����ܹ�������������Ϊ1�����������ĸ�λ�á�
// Ȼ������������չ���Ϳ��Ե�����һλ�á�
bool canJump(int x, int y, int x2, int y2) {
    return true;
}