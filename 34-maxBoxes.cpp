// �Ȱ�һά����Ȼ��������һά��DP

/*��ľ�Ķ���(�벻Ҫ�ڴ����ж���ýṹ)
struct Box {
  int vol, weight;
};*/
bool cmpBox(const Box &a, const Box &b)
{
    if (a.vol != b.vol)
        return a.vol < b.vol;
    else
        return a.weight < b.weight;
}
int maxBoxes(vector<Box> &boxes) {
    const int n = boxes.size();
    if (n < 2)
        return n;
    
    sort(boxes.begin(), boxes.end(), cmpBox);
    
    vector<int> dp(n, 1);
    int maxb = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if ((boxes[j].vol < boxes[i].vol) && (boxes[j].weight < boxes[i].weight))
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxb = max(maxb, dp[i]);
            }
        }
    }
    return maxb;
}