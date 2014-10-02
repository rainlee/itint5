// �Ӹ�λ��ʼ��,string�������Ǹ�λ����λ

//����a+b�Ľ��
string add(const string& a, const string& b) {
    if (a.empty() || a == "0")
        return b;
    if (b.empty() || b == "0")
        return a;
    
    string sum;
    int i = a.size()-1;
    int j = b.size()-1;
    int c = 0;
    while ((i >= 0) || (j >= 0) || c)
    {
        int na = (i >= 0) ? (a[i--] - '0') : 0;
        int nb = (j >= 0) ? (b[j--] - '0') : 0;
        int ab = na + nb + c;
        sum = (char)((ab % 10) + '0') + sum;
        c = ab / 10;
    }
    return sum;
}