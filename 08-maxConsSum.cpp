// 贪心，从前往后累加，累积和为负则丢弃，重新开始累加
// 记录中间出现的最大值
int maxConsSum(const vector<int> &arr) {
    if (arr.empty())
        return 0;
    
    int maxs = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        else
            maxs = max(maxs, sum);
    }
    return maxs;
}