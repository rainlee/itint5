// 要求空间O(1)
// 先排序，然后调用twoSumZero
// 去重方法，相同元素，前面的没有排，则后面的也不能排

typedef tuple<int, int, int> ABC; //存放a,b,c三元组
// 二元组相加等于target
void twoSumZero(const vector<int> &arr, int i1, vector<ABC> &vsum)
{
    ABC t;
    int low = i1+1;
    int high = arr.size()-1;
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (sum == -arr[i1])
        {
            get<0>(t) = arr[i1];
            get<1>(t) = arr[low];
            get<2>(t) = arr[high];
            vsum.push_back(t);
            ++low;
            --high;
            while ((low < high) && (arr[low] == arr[low-1]))
                ++low;
            while ((low < high) && (arr[high] == arr[high+1]))
                --high;
        }
        else if (sum > -arr[i1])
            --high;
        else
            ++low;
    }
}

//返回所有满足条件的(a,b,c)三元组
vector<ABC> threeSumZero(vector<int> &arr) {
    vector<ABC> vsum;
    if (arr.size() < 3) return vsum;
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size()-2; ++i)
    {
        if ((i > 0) && (arr[i] == arr[i-1]))
            continue;
        twoSumZero(arr, i, vsum);
    }
    return vsum;
}