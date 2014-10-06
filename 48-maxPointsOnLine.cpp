// 法1：枚举两点构成的线，然后检查其他点是否在该线上，时间复杂度O(n^3)
// 法2：枚举点，看穿过该点的所有线 有哪些斜率相等
// 注意：
// 1 处理重合点
// 2 double做map关键字的精度问题，可以用key/EPSILON
// 精度处理有问题，第26个用例错了

/*点的定义
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

// 法3：仍然是枚举点
// 不用map了，之间把所有的斜率存下来，然后排序，找出斜率相同最大的
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