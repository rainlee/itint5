// 两个指针i j分别遍历a b，取小的那个
// 加入小的和结果数组的最后一个相等，则不复制
vector<int> arrayUnion(vector<int> &a, vector<int> &b) {
    const int n = a.size();
    const int m = b.size();
    int i = 0;
    int j = 0;
    int tmp;
    vector<int> vau;
    while ((i < n) || (j < m))
    {
        if ((j >= m) || ((i < n) && (j < m) && (a[i] <= b[j])))
            tmp = a[i++];
        else
            tmp = b[j++];
        if (vau.empty() || (tmp != vau.back()))
            vau.push_back(tmp);
    }
    return vau;
}

// 两个指针i j分别遍历a b，取相等的
// 相同元素保留一个
vector<int> arrayIntersect(vector<int> &a, vector<int> &b) {
    vector<int> vai;
    if (a.empty() || b.empty()) return vai;
    
    const int n = a.size();
    const int m = b.size();
    int i = 0;
    int j = 0;
    while ((i < n) && (j < m))
    {
        if (a[i] < b[j])
            ++i;
        else if (a[i] > b[j])
            ++j;
        else
        {
            if (vai.empty() || (a[i] != vai.back()))
                vai.push_back(a[i]);
            ++i;
            ++j;
        }
    }
    return vai;
}