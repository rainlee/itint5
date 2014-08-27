//返回arr中所有元素之和
//不需要main函数!
int arrSum(const vector<int> &arr) {
    int sum = 0;
    for (auto &x : arr)
        sum += x;
    return sum;
}