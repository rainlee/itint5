// ���������������a+b > b+a����a����ǰ��
// ֱ�Ӱ��ֵ������Ǵ��
// ���� 1 10���ֵ���"10" > "1" ������110 > 101
bool cmpNum(const string &a, const string &b)
{
    return (a+b > b+a);
}
string biggestNum(vector<string> &nums) {
    string bnum;
    //sort(nums.begin(), nums.end(), greater<string>());
    sort(nums.begin(), nums.end(), cmpNum);
    for (int i = 0; i < nums.size(); ++i)
        bnum += nums[i];
    return bnum;
}