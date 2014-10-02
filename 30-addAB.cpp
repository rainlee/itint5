// 从个位开始加,string从左到右是高位到低位

//返回a+b的结果
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