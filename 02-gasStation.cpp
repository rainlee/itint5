#include <vector>
using namespace std;

int selectGasStation(const vector<int> &a, const vector<int> &g) {
    int suma = 0;
    int sumg = 0;
    int cost = 0;
    int istart = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        suma += a[i];
        sumg += g[i];
        cost += a[i] - g[i];
        if (cost < 0)
        {
            cost = 0;
            istart = i + 1;
        }
    }
    if (suma < sumg)
        return -1;
    else
        return istart;
}