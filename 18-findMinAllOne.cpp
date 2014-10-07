// �����жϸ�λ��ֻ��1 3 7 9������˵õ�1������֮�ⶼ������
// Ȼ������ģ��������ʣ�ÿ��ȡģ�������������
// (a * b) mod x = ((mx+a') * (nx+b')) mod x = (a' mod x) * (b' mod x) = (a mod x) * (b mod x)
int findMinAllOne(int a) {
    static const int M[] = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
    if (M[a % 10] == 0) return -1;
    if (a == 1) return 1;
    
    int res = 1;
    int h = 1;
    while (h)
    {
        h = (h*10 + 1) % a;
        ++res;
    }
    return res;
}