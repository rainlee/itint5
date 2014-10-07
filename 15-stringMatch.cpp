#include <algorithm>
/*
// 将str的所有子串求出来，放在set中
// 没加长度10的限制，第10个用例 内存超出限制
// 加了之后 数据14 运行超时

// 预处理初始化
unordered_set<string> shash;
void initWithString(char *str) {
    shash.clear();
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        for (int j = 1; (j <= 10) && (j <= len-i); ++j)
            shash.insert(string(str+i, j));
}
// 如果query是str的字串,返回true,否则返回false
bool existSubString(char *query) {
    return (shash.find(string(query)) != shash.end());
}
*/

/*
// 法2：字符串转换为数字，数组 + 二分查找
// 预处理：将子串通过“excel数转换”转为数字（子串长度<=10）
// 然后排序
// 查找子串的时候同意转为数字，然后二分查找
const int N = 26;
const char d2e[] = {
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'
};
//将excel数转换为十进制数
long long excelToDec(string excelNum) {
    long long d = 0;
    for (int i  = 0; i < excelNum.size(); ++i)
    {
        d = d * N + (excelNum[i] - 'A') + 1;  // 'A' means 1
    }
    return d;
}

vector<long long> vsubs;
void initWithString_2(char *str) {
    vsubs.clear();
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        for (int j = 1; (j <= 10) && (j <= len-i); ++j)
            vsubs.push_back(excelToDec(string(str+i, j)));
    sort(vsubs.begin(), vsubs.end());
}

bool existSubString_2(char *query) {
    return binary_search(vsubs.begin(), vsubs.end(), excelToDec(string(query)));
}
*/

/*
// 用set unordered_set均会超时
set<long long> ssubs;
void initWithString_3(char *str) {
    ssubs.clear();
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        for (int j = 1; (j <= 10) && (j <= len-i); ++j)
            ssubs.insert(excelToDec(string(str+i, j)));
}

bool existSubString_3(char *query) {
    return (ssubs.find(excelToDec(string(query))) != ssubs.end());
}
*/

// 法3：方法同法2，数组 + 二分
// 不用转换，直接将长度=10的子串存在vector中，排序
// 查找时直接二分查找，前缀匹配
vector<string> vsubs;
void initWithString_4(char *str) {
    vsubs.clear();
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (i + 10 >= len)
            vsubs.push_back(string(str + i));
        else
            vsubs.push_back(string(str + i, 10));
    }
    sort(vsubs.begin(), vsubs.end());
}
bool existSubString_4(char *query) {
    string sq(query);
    int low = 0;
    int high = vsubs.size() - 1;
    while (low <= high)
    {
        int mid = (low&high) + ((low^high) >> 1);
        bool found = true;
        for (int i = 0; i < sq.size(); ++i)
        {
            if (vsubs[mid][i] < sq[i])
            {
                low = mid + 1;
                found = false;
                break;
            }
            else if (vsubs[mid][i] > sq[i])
            {
                high = mid - 1;
                found = false;
                break;
            }
        }
        if (found)
            return true;
    }
    return false;
}


void initWithString(char *str) {
    initWithString_4(str);
}
bool existSubString(char *query) {
    return existSubString_4(query);
}