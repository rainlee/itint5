// DP 求出矩阵每一点是否能到达
// 使(x,y)在左上角 (x2,y2)在右下角，副对角线转换成主对角线
/*
void preProcess(int &x, int &y, int &x2, int &y2)
{
    if ((x < 0) || (x2 < 0))
    {
        int minx = min(x, x2);  // 偏移到正数
        int k = -minx;
        x += k;
        x2 += k;
    }
    if ((y < 0) || (y2 < 0))
    {
        int miny = min(y, y2);  // 偏移到正数
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
    else if ((y2 - y) * (x2 - x) > 0)  // 主对角线
    {
        if (x > x2)
        {
            swap(x, x2);
            swap(y, y2);
        }
    }
    else  // 副对角线
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

// 法1 过不了……
// 由于棋盘无限大，所以马能够到达任一位置。
// 为了证明这个结论，可以先画图证明马能够到达离它距离为1的上下左右四个位置。
// 然后依次向外扩展，就可以到达任一位置。
bool canJump(int x, int y, int x2, int y2) {
    return true;
}