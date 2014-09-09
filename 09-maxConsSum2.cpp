// 1. �ǻ��ε����ֱ��Ӧ�á���������Ӷκ͡��Ľⷨ�����ֵΪM_1��
// 2. ���ڻ��Σ��������С�����Ӷκ͡�������������ĺ�sum��ȥ��С�����Ӷκ���Ϊ�������ֵM_2��
// 3. ����M_1��M_2�нϴ��ߡ�
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