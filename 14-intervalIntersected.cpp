/*
struct Interval {
    int start;   //区间左端点
    int end;   //区间右端点
};
*/

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交

// 枚举，两两比较，时间复杂度O(n^2)
/*
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    if (intervals.empty())
        return;
    
    for (int i = 0; i < intervals.size(); ++i)
    {
        //if (isIntersected[i])  // 已经相交，不用判断了
        //    continue;          // 已经相交也要判断，可能多次相交
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

// 法1超时
// 法2：先对区间按start排序，然后遍历一次，记录最右位置，判断是否相交
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