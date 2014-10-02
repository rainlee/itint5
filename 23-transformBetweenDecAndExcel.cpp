// 二十六进制
// 0怎么表示？
// d2e时 注意没有0，decNum每次都-1
// e2d时 注意A对应1，不是0

const int N = 26;
const char d2e[] = {
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'
};

//将十进制数转换为excel数
string decToExcel(int decNum) {
    string e;
    while (decNum)
    {
        decNum -= 1;
        e = d2e[decNum % N] + e;  // Z 26
        decNum /= N;
    }
    return e;
}

//将excel数转换为十进制数
int excelToDec(string excelNum) {
    int d = 0;
    for (int i  = 0; i < excelNum.size(); ++i)
    {
        d = d * N + (excelNum[i] - 'A') + 1;  // 'A' means 1
    }
    return d;
}