// Ϊ�����ظ��ƶ�Ԫ�أ���ͳ�ƿո�ĸ�����Ȼ������ת����Ŀռ䣬�Ӻ���ǰת��
void escapeSpace(char *str) {
    if (!str) return;
    int cnt = 0;
    int len = 0;
    char *p = str;
    while (*p != '\0')
    {
        ++len;
        if (*p == ' ')
            ++cnt;
        ++p;
    }
    int i = len - 1;
    int j = len + 2*cnt - 1;
    while ((i >= 0) && (j >= 0))
    {
        if (str[i] != ' ')
            str[j--] = str[i--];
        else
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;
        }
    }
}