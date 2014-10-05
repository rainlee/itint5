// 先排序，排序规则是a+b > b+a，则将a排在前面
// 直接按字典序排是错的
// 比如 1 10，字典序"10" > "1" ，但是110 > 101
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