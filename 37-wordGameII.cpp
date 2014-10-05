// ��1��ֱ�ӵ���dfs
// ��ʱ
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

bool exists_dfs(vector<vector<char> > &grid, string &pattern) {
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

bool exists_1(vector<vector<char> > &grid, vector<string> &patterns) {
    for (int i = 0; i < patterns.size(); ++i)
        if (exists_dfs(grid, patterns[i]))
            return true;
    return false;
}

// ��2�������е�pattern����һ��trie��
// ���A��B��ǰ׺����ֻ��Ҫ�ж��ܷ����������ҵ�A�Ϳ����ˣ�����Ҫ��B��
// ��Ȼʹ��DFS����Trie���ĸ����²��ң�ֱ���ҵ�һ��������pattern
struct Node {
        bool end;
        vector<Node *> children;
        Node(): end(false) {
            children.resize(26, NULL);
        }
};
class Trie {
public:
    Node *root;
    Trie() : root(NULL) {}
    void addTrie(string &pattern) {
        Node *cur = root;
        for (int i = 0; i < pattern.size(); ++i)
        {
            if (cur->end)  // ֻ��¼���ǰ׺
                return;
            int c = pattern[i] - 'A';
            if (cur->children[c] == NULL)
                cur->children[c] = new Node;
            cur = cur->children[c];
        }
        cur->end = true;
    }
    void buildTrie(vector<string> &patterns) {
        if (!root)
            root = new Node;
        for (int i = 0; i < patterns.size(); ++i)
            addTrie(patterns[i]);
    }
};

bool dfs2(vector<vector<char> > &grid, int x, int y, Node *node, vector<vector<bool> > &visited)
{
    const int n = grid.size();
    const int m = grid[0].size();
    if (!node)
        return false;
    if (node->end)
        return true;
    
    visited[x][y] = true;
    bool res = false;
    for (int i = 0; i < 4; ++i)
    {
        int x2 = x + directions[i][0];
        int y2 = y + directions[i][1];
        if ((x2 < 0) || (x2 >= n) || (y2 < 0) || (y2 >= m) || visited[x2][y2])
            continue;
        if (dfs2(grid, x2, y2, node->children[grid[x2][y2]-'A'], visited))  // ������һ���ַ�
        {
            res = true;
            break;
        }
    }
    visited[x][y] = false;
    return res;
}

bool exists_2(vector<vector<char> > &grid, vector<string> &patterns) {
    Trie trie;
    trie.buildTrie(patterns);
    if (trie.root->end)  // patterns���пմ�
        return true;
    
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (dfs2(grid, i, j, trie.root->children[grid[i][j]-'A'], visited))
                return true;
    }
    return false;
}

bool exists(vector<vector<char> > &grid, vector<string> &patterns) {
    return exists_2(grid, patterns);
}