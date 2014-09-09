// 检查 行 列 块
// 分别用一个int的低9位记录9个数
int isValidSudoku(int arr[]) {
    const int N = 9;
    vector<int> brow(N, 0);
    vector<int> bcol(N, 0);
    vector<int> bbox(N, 0);
    
    const int N2 = N * N;
    for (int i = 0; i < N2; ++i)
    {
        if (arr[i] > 9 || arr[i] < 1)
            return false;
        
        int row = i / N;
        int col = i % N;
        int box = row/3 * 3 + col/3;
        
        int bit = 1 << arr[i];
        if ((brow[row] & bit) || (bcol[col] & bit) || (bbox[box] & bit))
            return false;
        
        brow[row] |= bit;
        bcol[col] |= bit;
        bbox[box] |= bit;
    }
    return true;
}