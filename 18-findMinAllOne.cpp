// 首先判断个位，只有1 3 7 9可以相乘得到1，除此之外都不可能
// 然后利用模运算的性质，每次取模，避免大数运算
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