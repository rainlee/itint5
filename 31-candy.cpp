// ��1������2��
// �����ң������ұߴ�Ķ��һ��
// �������󣬵�����������ߴ�Ķ��һ��
// ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)

//����������Ҫ���ǹ���
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

// ��2������1�� ���뷨
// ��¼����ֵmaxv ������maxi ��һ��Ԫ��ֵlast
// ��ratings[i] > ratings[i-1]ʱ������maxv ����last
//              =               , maxv = last = 1
//              <               , ��ʱ��ǰiλ�����ٸ�1��
// ��last > 1�����㹻������last=1��maxv���ֲ���
//        =  , ǰ������ˣ���Ҫ����[maxi, i)
// ��maxv�㹻�� maxv > i - maxi����ֱ�Ӳ���(maxi, i) ÿ����һ��
//                   <=        ���򲻹�����maxv++��[maxi, i) ÿ����һ��
// ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
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
            maxv = last;   // ���¼���ֵ
            maxi = i;
        }
        else
        {
            if (last == 1)  // ���� ��Ҫ��
            {
                if (maxv > i - maxi)
                    sum += i - maxi - 1;
                else
                {
                    ++maxv;   // maxv��Ҫ��һ�ţ�maxi����
                    sum += i - maxi;
                }
            }
            last = 1;  // ��ǰ�Ǽ�Сֵ
        }
        sum += last;  // ���ϵ�ǰֵ
    }
    return sum;
}

long long minimalCandies(vector<int> &ratings) {
    return minimalCandies_2(ratings);
}