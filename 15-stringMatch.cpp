#include <algorithm>
/*
// ��str�������Ӵ������������set��
// û�ӳ���10�����ƣ���10������ �ڴ泬������
// ����֮�� ����14 ���г�ʱ

// Ԥ�����ʼ��
unordered_set<string> shash;
void initWithString(char *str) {
    shash.clear();
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        for (int j = 1; (j <= 10) && (j <= len-i); ++j)
            shash.insert(string(str+i, j));
}
// ���query��str���ִ�,����true,���򷵻�false
bool existSubString(char *query) {
    return (shash.find(string(query)) != shash.end());
}
*/

/*
// ��2���ַ���ת��Ϊ���֣����� + ���ֲ���
// Ԥ�������Ӵ�ͨ����excel��ת����תΪ���֣��Ӵ�����<=10��
// Ȼ������
// �����Ӵ���ʱ��ͬ��תΪ���֣�Ȼ����ֲ���
const int N = 26;
const char d2e[] = {
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'
};
//��excel��ת��Ϊʮ������
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
// ��set unordered_set���ᳬʱ
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

// ��3������ͬ��2������ + ����
// ����ת����ֱ�ӽ�����=10���Ӵ�����vector�У�����
// ����ʱֱ�Ӷ��ֲ��ң�ǰ׺ƥ��
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