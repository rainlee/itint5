// dfs, 保证左括号数 >= 右括号数
void genRec(int left, int right, string path, vector<string> &vpares)
{
    if (0 == left)
    {
        path += string(right, ')');
        vpares.push_back(path);
        return;
    }
    genRec(left - 1, right, path + '(', vpares);
    if (right > left)
        genRec(left, right - 1, path + ')', vpares);
}
vector<string> generate(int n) {
    vector<string> vpares;
    string path;
    genRec(n, n, path, vpares);
    return vpares;
}