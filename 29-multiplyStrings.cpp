// ��iλ * ��jλ = �������i+jλ
// ע�⣺���ţ���λ

//����a*b�Ľ��
string multiply(const string& a, const string& b) {
    if ((a == "0") || (b == "0"))
        return "0";
    
    const int n = a.size();
    const int m = b.size();
    vector<int> vmul(n+m, 0);
    for (int i = n-1; (i >= 0) && isdigit(a[i]); --i)
    {
        for (int j = m-1; (j >= 0) && isdigit(b[j]); --j)
        {
            int i2 = n - i - 1;
            int j2 = m - j - 1;
            int tmp = (a[i] - '0') * (b[j] - '0');
            vmul[i2 + j2] += tmp;
            vmul[i2 + j2 + 1] += vmul[i2 + j2] / 10;
            vmul[i2 + j2] %= 10;
        }
    }
    
    string smul;
    if (((a[0] == '-') && (b[0] != '-')) || ((a[0] != '-') && (b[0] == '-')))
        smul += "-";
    int i = vmul.size() - 1;
    while (vmul[i] == 0)
        --i;
    for ( ; i >= 0; --i)
        smul += char(vmul[i] + '0');
    return smul;    
}