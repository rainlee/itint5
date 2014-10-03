#include <stack>

// �ݹ�
// ��ȡ�����֣�Ȼ��"+,-"����ֱ������"*"��Ҫ�˽����ŵ�һ����
// Ϊ���㣬�ݹ麯�������һ��������������"+"����1 "-"����-1

int getNumber(const string &expr, int &i)
{
    int num = 0;
    while ((i < expr.size()) && isdigit(expr[i]))
        num = num * 10 + (expr[i++] - '0');
    return num;
}

// n�����һ��������
int calRec(const string &expr, int i, int n)
{
    n *= getNumber(expr, i);
    if (i >= expr.size())
        return n;
    if (expr[i] == '*')
        return calRec(expr, i+1, n);
    if (expr[i] == '+')
        return n + calRec(expr, i+1, 1);
    if (expr[i] == '-')
        return n + calRec(expr, i+1, -1);
}

// ��2������
int evaluate_2(const string &expr) {
    int res = 0;
    int n = 1;
    for (int i = 0; i < expr.size(); ++i)
    {
        n *= getNumber(expr, i);
        if (i >= expr.size())
        {
            res += n;
            break;
        }
        if (expr[i] == '+')  // + -����ֱ�Ӽ����ܽ��
        {
            res += n;
            n = 1;
        }
        else if (expr[i] == '-')
        {
            res += n;
            n = -1;
        }
    }
    return res;
}

// ��3��˫ջ ����ջ ����ջ
// ����������ѹ����ջ
// �����������������ջΪ�գ�ֱ��ѹջ������ǰ������������ջ�����ţ����ȼ���ջ�еı��ʽ����ѹ��ǰ����
void calExp(stack<int> &snum, stack<char> &sop)
{
    while (!sop.empty())
    {
        int num2 = snum.top(); snum.pop();   // num2 first
        int num1 = snum.top(); snum.pop();
        switch (sop.top())
        {
            case '+':
                snum.push(num1 + num2);
                break;
            case '-':
                snum.push(num1 - num2);
                break;
            case '*':
                snum.push(num1 * num2);
                break;
        }
        sop.pop();
    }
}
int evaluate_3(const string &expr) {
    stack<char> sop;
    stack<int> snum;
    for (int i = 0; i < expr.size(); ++i)
    {
        int num = getNumber(expr, i);
        snum.push(num);
        if (i >= expr.size())
            break;
        if ((expr[i] == '+') || (expr[i] == '-') || (expr[i] == '*'))
        {
            if (sop.empty())
                sop.push(expr[i]);
            else
            {
                if ((expr[i] == '+') || (expr[i] == '-')) // cal '*'
                    calExp(snum, sop);
                sop.push(expr[i]);
            }
        }
    }
    calExp(snum, sop);
    return snum.top();
}

// ��4���Ƚ�ǰ׺���ʽתΪ��׺���ʽ���沨��ʽ����Ȼ������沨��ʽ
// ��׺���ʽת��׺���ʽ��ѭ����ԭ��
// 1.������������ֱ�������
// 2.ջΪ��ʱ���������������ջ��
// 3.���������ţ�������ջ��
// 4.���������ţ�ִ�г�ջ������������ջ��Ԫ�������ֱ������ջ���������ţ������Ų������
// 5.�������������'+''-''*''/'ʱ�������������ȼ����ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ��
// 6.���ս�ջ�е�Ԫ�����γ�ջ�������
// �����沨��ʽ��
// ����ѹ������ջ���������ţ��򵯳���������������

// ������������ȼ�
int priority(char op)
{
    switch (op)
    {
        case '(':  
            return 0;  
        case '+':  
        case '-':  
            return 1;  
        case '*':  
        case '/':  
            return 2;  
        default :  
            return -1;
    }
}
void postfix(const string &expr, vector<string> &vrpe)
{
    stack<char> sop;  // ��������ջ
    for (int i = 0; i < expr.size(); ++i)
    {
        int num = getNumber(expr, i);
        vrpe.push_back(to_string(num));
        if (i >= expr.size())
            break;
        if (sop.empty())
            sop.push(expr[i]);
        else
        {
            while (!sop.empty() && (priority(expr[i]) <= priority(sop.top())))
            {
                vrpe.push_back(string(1, sop.top()));
                sop.pop();
            }
            sop.push(expr[i]);
        }
    }
    while (!sop.empty())
    {
        vrpe.push_back(string(1, sop.top()));
        sop.pop();
    }
}

// Calculate Reverse Polish Expression
int calRPE(vector<string> &vrpe)
{
    stack<int> snum;
    for (int i = 0; i < vrpe.size(); ++i)
    {
        if ((vrpe[i] == "+") || (vrpe[i] == "-") || (vrpe[i] == "*"))
        {
            int num2 = snum.top(); snum.pop();
            int num1 = snum.top(); snum.pop();
            switch (vrpe[i][0])
            {
                case '+':
                    snum.push(num1 + num2);
                    break;
                case '-':
                    snum.push(num1 - num2);
                    break;
                case '*':
                    snum.push(num1 * num2);
                    break;
            }
        }
        else
            snum.push(stoi(vrpe[i]));
    }
    return snum.top();
}

int evaluate_4(const string &expr) {
    vector<string> vrpe;
    postfix(expr, vrpe);
    return calRPE(vrpe);
}

//���ر��ʽexpr��ֵ
int evaluate(const string& expr) {
    //return calRec(expr, 0, 1);
    //return evaluate_2(expr);
    //return evaluate_3(expr);
    return evaluate_4(expr);
}