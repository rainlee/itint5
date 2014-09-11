/*
1. ����dx=x-x2,dy=y-y2��
2. ���p,q�����Լ��g�����dx����dy���ܱ�g��������ô����Ȼ�޽⡣
3. ��p,q,dx,dy������g������p��q�����ˡ�
4. ע�⵽������������(0,2p)����(p,q)��һ�£�Ȼ��(p,-q)��һ�£����ظ�������̣�
   ��������������(0,2kp)�ĵ㣬���ڶԳ��ԣ�Ҳ������������(2kp,0)�ĵ㡣 
5.������һ���ܹؼ�������p,q���ʣ���ô����x,y����px+qy=1����չŷ����¶�������
   ����������������(0,2)�ͺ�(2,0)�����ڶԳ��ԣ������������������궼Ϊż���㡣
6. ��������Ľ��ۣ���ʵֻ�ÿ���(0,0),(0,1),(1,0),(1,1)��4�����Ƿ�ɴ
   (0,0)�ǿɴ�ģ�(0,1)��(1,0)���ڶԳ���ֻ�ÿ���(0,1)��
7. ����(1,1)����ʵ����Զ�ɴ�ġ�
   ���q,p��Ϊ����������������(1+p,1+q)�ĵ㣨����5�еĽ��ۣ�������������ż���ĵ㣩��Ȼ��(-p,-q)����(1,1)��
   ���p,qһ��һż������������(1+p+q,1+q+p)�ĵ㣨����5�еĽ��ۣ���Ȼ��(-p,-q),(-q,-p)��������(1,1)��
8. ����(0,1)��
   ���p,qһ��һż����ôҲ����Զ�ɴ�ģ�ͬ7��֤����
   ���p,q������������ô�ǲ���������(0,1)�ģ���Ϊ��������������ô�Ӽ��������㶼�����ܱ��һ��һż��
�������Ľ��۾��ǣ���3��֮�����p,qһ��һż����ô�ɴ����dx,dyͬ���ͬż�ſɴ
*/
int gcd(int a, int b)
{
    return (0 == b) ? a : gcd(b, a%b);
}

bool canJump(int p, int q, int x, int y, int x2, int y2) {
    if(p == 0 && q == 0) 
        return (x==x2 && y==y2);
    
    int dx = x - x2;
    int dy = y - y2;
    
    int g = gcd(p, q);    
    if ((0 != dx%g) || (0 != dy%g))
        return false;
    
    if ((p + q) & 0x01)
        return true;
    else if (!((dx + dy) & 0x01))
        return true;
    else
        return false;
}