// ̰�ģ���ǰ�����ۼӣ��ۻ���Ϊ�����������¿�ʼ�ۼ�
// ��¼�м���ֵ����ֵ
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