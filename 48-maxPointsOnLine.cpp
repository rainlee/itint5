// ��1��ö�����㹹�ɵ��ߣ�Ȼ�����������Ƿ��ڸ����ϣ�ʱ�临�Ӷ�O(n^3)
// ��2��ö�ٵ㣬�������õ�������� ����Щб�����
// ע�⣺
// 1 �����غϵ�
// 2 double��map�ؼ��ֵľ������⣬������key/EPSILON
// ���ȴ��������⣬��26����������

/*��Ķ���
struct Point {double x,y;}
*/
const double EPSILON = 0.0000001;
int maxPointsOnLine_1(vector<Point> &points) {
    if (points.size() < 3)
        return points.size();
    
    const int n = points.size();
    int maxp = 2;
    for (int i = 0; i < n; ++i)
    {
        int samep = 1;
        int maxc = 0;  // max count
        unordered_map<double, int> lines;  // slope - count
        double slope;
        for (int j = i+1; j < n; ++j)
        {
            if ((abs(points[i].x - points[j].x) <= EPSILON) && (abs(points[i].y - points[j].y) <= EPSILON))
            {
                ++samep;
                continue;
            }
            if (abs(points[i].x - points[j].x) <= EPSILON)
                slope = std::numeric_limits<double>::infinity();
            else
                slope = floor((points[i].y - points[j].y) / (points[i].x - points[j].x) / EPSILON);
            lines[slope]++;
            maxc = max(maxc, lines[slope]);
        }
        maxp = max(maxp, samep + maxc);
    }
    return maxp;
}

// ��3����Ȼ��ö�ٵ�
// ����map�ˣ�֮������е�б�ʴ�������Ȼ�������ҳ�б����ͬ����
int maxPointsOnLine_2(vector<Point> &points) {
    if (points.size() < 3)
        return points.size();
    
    const int n = points.size();
    int maxp = 2;
    for (int i = 0; i < n; ++i)
    {
        int samep = 1;
        int maxc = 0;  // max count
        vector<double> lines;  // slope - count
        double slope;
        for (int j = i+1; j < n; ++j)
        {
            if ((abs(points[i].x - points[j].x) <= EPSILON) && (abs(points[i].y - points[j].y) <= EPSILON))
            {
                ++samep;
                continue;
            }
            if (abs(points[i].x - points[j].x) <= EPSILON)
                slope = std::numeric_limits<double>::max();
            else
                slope = (points[i].y - points[j].y) / (points[i].x - points[j].x);
            lines.push_back(slope);
        }
        sort(lines.begin(), lines.end());
        for (int i = 0; i < lines.size(); )
        {
            int j = i+1;
            while ((j < lines.size()) && (abs(lines[j] - lines[i]) <= EPSILON))
                ++j;
            maxc = max(maxc, j-i);
            i = j;
        }
        maxp = max(maxp, samep + maxc);
    }
    return maxp;
}

int maxPointsOnLine(vector<Point> &points) {
    return maxPointsOnLine_2(points);
}