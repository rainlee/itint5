// 1. 非环形的情况直接应用“最大连续子段和”的解法，最大值为M_1。
// 2. 对于环形，求出“最小连续子段和”。用整个数组的和sum减去最小连续子段和则为环形最大值M_2。
// 3. 返回M_1和M_2中较大者。
int maxConsSum(const vector<int> &arr) {
    int sum = 0;
    int maxs = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum = max(arr[i], sum + arr[i]);
        maxs = max(maxs, sum);
    }
    return maxs;
}
int minConsSum(const vector<int> &arr) {
    int sum = 0;
    int mins = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum = min(arr[i], sum + arr[i]);
        mins = min(mins, sum);
    }
    return mins;
}

int maxConsSum2(const vector<int> &arr) {
    if (arr.empty())
        return 0;
    
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
        sum += arr[i];
    int maxs = maxConsSum(arr);
    int mins = minConsSum(arr);
    
    return max(maxs, sum - mins);
}