// 从左上角开始查找，每次去掉一行或者一列
bool exists(vector<vector<int> > &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;
    const int n = matrix.size();
    const int m = matrix[0].size();
    int row = 0;
    int col = m - 1;
    while ((row < n) && (col >= 0))
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            --col;
        else
            ++row;
    }
    return false;
}