// BFS / DFS + 标记数组
// BFS是错误的，反例
// ["AB","BC"], "ABCB"，应该返回true，bfs返回false
// 因为bfs每次将周围可访问点都标记为已访问true，而实际上这时候还没有访问到该点……
// bfs的代码也能通过所有测试用例，因为测试用例不强
int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
bool dfs(vector<vector<char> > &grid, int x, int y, string &pattern, int k, vector<vector<bool> > &visited)
{
    const int n = grid.size();
    const int m = grid[0].size();
    if (grid[x][y] != pattern[k])
        return false;
    if (k == pattern.size()-1)
        return true;
    visited[x][y] = true;
    bool res = false;
    for (int i = 0; i < 4; ++i)
    {
        int x2 = x + directions[i][0];
        int y2 = y + directions[i][1];
        if ((x2 < 0) || (x2 >= n) || (y2 < 0) || (y2 >= m) || visited[x2][y2])
            continue;
        if (dfs(grid, x2, y2, pattern, k+1, visited))
        {
            res = true;
            break;
        }
    }
    visited[x][y] = false;
    return res;
}

bool exists_1(vector<vector<char> > &grid, string &pattern) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (dfs(grid, i, j, pattern, 0, visited))
                return true;
    }
    return false;
}

// BFS
struct Node {
    int x;
    int y;
    Node(int x, int y): x(x), y(y) {}
};
bool bfs(vector<vector<char> > &grid, int x, int y, string &pattern) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    queue<pair<Node, int> > q;     // node - step
    q.push(make_pair(Node(x, y), 0));
    visited[x][y] = true;
    while (!q.empty())
    {
        int x1 = q.front().first.x;
        int y1 = q.front().first.y;
        int step = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int x2 = x1 + directions[i][0];
            int y2 = y1 + directions[i][1];
            if ((x2 < 0) || (x2 >= n) || (y2 < 0) || (y2 >= m) || visited[x2][y2] || (grid[x2][y2] != pattern[step+1]))
                continue;
            if (step + 1 == pattern.size() - 1)
                return true;
            q.push(make_pair(Node(x2, y2), step+1));
            visited[x2][y2] = true;
        }
    }
    return false;
}

bool exists_2(vector<vector<char> > &grid, string &pattern) {
    const int n = grid.size();
    const int m = grid[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if ((grid[i][j] == pattern[0]) && ((pattern.size() == 1) || bfs(grid, i, j, pattern)))
                return true;
    }
    return false;
}

bool exists(vector<vector<char> > &grid, string pattern) {
    return exists_1(grid, pattern);
}
