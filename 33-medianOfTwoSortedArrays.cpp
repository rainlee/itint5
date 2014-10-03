// 比较arr1[k/2] 和 arr2[k/2]
// 扔掉小者的前半部分 大者的后半部分
// 时间复杂度O(log(m+n))
int findKth(vector<int> &arr1, int start1, int n, 
            vector<int> &arr2, int start2, int m, int k)
{
    if (n > m)
        return findKth(arr2, start2, m, arr1, start1, n, k);
    if (0 == n)
        return arr2[start2 + k - 1];
    if (1 == k)
        return min(arr1[start1], arr2[start2]);
    
    int i1 = min(n, k/2);
    int i2 = k - i1;
    if (arr1[start1 + i1 - 1] == arr2[start2 + i2 - 1])
        return arr1[start1 + i1 - 1];
    else if (arr1[start1 + i1 - 1] > arr2[start2 + i2 - 1])
        return findKth(arr1, start1, i1, arr2, start2+i2, m-i2, k-i2);
    else
        return findKth(arr1, start1+i1, n-i1, arr2, start2, i2, k-i1);
}
int median(vector<int> &arr1, vector<int> &arr2) {
    const int n = arr1.size();
    const int m = arr2.size();
    if ((m+n) & 0x1)
        return findKth(arr1, 0, n, arr2, 0, m, (m+n)/2 + 1);
    else
        return (findKth(arr1, 0, n, arr2, 0, m, (m+n)/2) + findKth(arr1, 0, n, arr2, 0, m, (m+n)/2 + 1)) / 2;
}