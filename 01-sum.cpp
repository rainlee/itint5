//����arr������Ԫ��֮��
//����Ҫmain����!
int arrSum(const vector<int> &arr) {
    int sum = 0;
    for (auto &x : arr)
        sum += x;
    return sum;
}