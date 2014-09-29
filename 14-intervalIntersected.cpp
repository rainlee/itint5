/*
struct Interval {
    int start;   //������˵�
    int end;   //�����Ҷ˵�
};
*/

// intervals����n������
// �����ŵ�isIntersected��(�ѷ���ռ�,����Ҫpush_back)
// isIntersected[i]��ʾ��i�������Ƿ������������ཻ

// ö�٣������Ƚϣ�ʱ�临�Ӷ�O(n^2)
/*
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    if (intervals.empty())
        return;
    
    for (int i = 0; i < intervals.size(); ++i)
    {
        //if (isIntersected[i])  // �Ѿ��ཻ�������ж���
        //    continue;          // �Ѿ��ཻҲҪ�жϣ����ܶ���ཻ
        for (int j = i+1; j < intervals.size(); ++j)
        {
            if (!((intervals[i].start > intervals[j].end) || (intervals[i].end < intervals[j].start)))
            {
                isIntersected[i] = true;
                isIntersected[j] = true;
            }
        }
    }
}
*/

// ��1��ʱ
// ��2���ȶ����䰴start����Ȼ�����һ�Σ���¼����λ�ã��ж��Ƿ��ཻ
bool cmpIntv(const pair<Interval, int> &v1, const pair<Interval, int> &v2)
{
    if (v1.first.start < v2.first.start)
        return true;
    else if (v1.first.start == v2.first.start)
        return v1.first.end < v2.first.end;
    else
        return false;
}
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    if (intervals.empty())
        return;
    
    const int n = intervals.size();
    vector<pair<Interval, int> > intvs(n);
    for (int i = 0; i < n; ++i)
        intvs[i] = make_pair(intervals[i], i);
    
    sort(intvs.begin(), intvs.end(), cmpIntv);
    
    int maxend = intvs[0].first.end;
    int last = 0;
    for (int i = 1; i < n; ++i)
    {
        if (intvs[i].first.start <= maxend)
        {
            isIntersected[intvs[last].second] = true;
            isIntersected[intvs[i].second] = true;
        }
        if (intvs[i].first.end > maxend)
        {
            maxend = intvs[i].first.end;
            last = i;
        }
    }
}