#include <stack>

// 递归
// 先取出数字，然后"+,-"可以直接做，"*"需要乘紧接着的一个数
// 为方便，递归函数传入第一个操作数，并且"+"乘以1 "-"乘以-1

int getNumber(const string &expr, int &i)
{
    int num = 0;
    while ((i < expr.size()) && isdigit(expr[i]))
        num = num * 10 + (expr[i++] - '0');
    return num;
}

// n代表第一个操作数
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

// 法2：迭代
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
        if (expr[i] == '+')  // + -可以直接加入总结果
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

// 法3：双栈 符号栈 数据栈
// 遇到数据则压数据栈
// 遇到运算符，若数据栈为空，直接压栈，若当前运算符级别低于栈顶符号，则先计算栈中的表达式，再压当前符号
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

// 法4：先将前缀表达式转为后缀表达式（逆波兰式），然后计算逆波兰式
// 中缀表达式转后缀表达式遵循以下原则：
// 1.遇到操作数，直接输出；
// 2.栈为空时，遇到运算符，入栈；
// 3.遇到左括号，将其入栈；
// 4.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出；
// 5.遇到其他运算符'+''-''*''/'时，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈；
// 6.最终将栈中的元素依次出栈，输出。
// 计算逆波兰式：
// 数字压入数据栈，遇到符号，则弹出两个操作数计算

// 计算运算符优先级
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
    stack<char> sop;  // 辅助符号栈
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

//返回表达式expr的值
int evaluate(const string& expr) {
    //return calRec(expr, 0, 1);
    //return evaluate_2(expr);
    //return evaluate_3(expr);
    return evaluate_4(expr);
}