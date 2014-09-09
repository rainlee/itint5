// 从后向前 找到第一个破坏递增顺序的数i
// 再次从后向前，找到第一个大于i的数，两者交换
// 将i位置后的数逆序
// 若当前已经是最大排列，则返回false
bool next_permutation(vector<int> &arr) {
    int i = arr.size() - 2;
    for (; (i >= 0) && (arr[i] >= arr[i+1]); --i) ;
    
    if (i < 0)
        return false;
         
    int j = arr.size() - 1;
    for (; (j > i) && (arr[j] <= arr[i]); --j) ;
    
    swap(arr[i], arr[j]);
    int low = i + 1;
    int high = arr.size() - 1;
    while (low < high)
         swap(arr[low++], arr[high--]);
    
    return true;
}