// ��ʮ������
// 0��ô��ʾ��
// d2eʱ ע��û��0��decNumÿ�ζ�-1
// e2dʱ ע��A��Ӧ1������0

const int N = 26;
const char d2e[] = {
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'
};

//��ʮ������ת��Ϊexcel��
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

//��excel��ת��Ϊʮ������
int excelToDec(string excelNum) {
    int d = 0;
    for (int i  = 0; i < excelNum.size(); ++i)
    {
        d = d * N + (excelNum[i] - 'A') + 1;  // 'A' means 1
    }
    return d;
}