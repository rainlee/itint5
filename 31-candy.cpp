// 法1：遍历2次
// 从左到右，满足右边大的多分一颗
// 从右往左，调整，满足左边大的多分一颗
// 时间复杂度O(n) 空间复杂度O(n)

//返回最少需要的糖果数
long long minimalCandies_1(vector<int> &ratings) {
    if (ratings.empty()) return 0;
    
    const int n = ratings.size();
    vector<long long> candy(n, 1);
    for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i-1])
            candy[i] = candy[i-1] + 1;
    
    long long sum = candy[n-1];
    for (int i = n-2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i+1])
            candy[i] = max(candy[i], candy[i+1] + 1);
        sum += candy[i];
    }
    return sum;
}

// 法2：遍历1次 补齐法
// 记录极大值maxv 及索引maxi 上一个元素值last
// 当ratings[i] > ratings[i-1]时，增加maxv 更新last
//              =               , maxv = last = 1
//              <               , 这时候当前i位置最少给1个
// 若last > 1，则足够，更新last=1，maxv保持不变
//        =  , 前面分少了，需要补齐[maxi, i)
// 若maxv足够大 maxv > i - maxi，则直接补齐(maxi, i) 每个补一颗
//                   <=        ，则不够补，maxv++，[maxi, i) 每个补一颗
// 时间复杂度O(n) 空间复杂度O(1)
long long minimalCandies_2(vector<int> &ratings) {
    if (ratings.empty()) return 0;
    
    const int n = ratings.size();
    
    long long last = 1;  // i=0
    long long sum = 1;
    long long maxv = 1;
    int maxi = 0;
    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] >= ratings[i-1])
        {
            last = (ratings[i] == ratings[i-1]) ? 1 : (last + 1);
            maxv = last;   // 更新极大值
            maxi = i;
        }
        else
        {
            if (last == 1)  // 不够 需要补
            {
                if (maxv > i - maxi)
                    sum += i - maxi - 1;
                else
                {
                    ++maxv;   // maxv需要补一颗，maxi不变
                    sum += i - maxi;
                }
            }
            last = 1;  // 当前是极小值
        }
        sum += last;  // 加上当前值
    }
    return sum;
}

long long minimalCandies(vector<int> &ratings) {
    return minimalCandies_2(ratings);
}