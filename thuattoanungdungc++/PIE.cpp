#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159
int n, f, t;
int radious[10000];
bool check(double mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += int((radious[i] * radious[i] * PI) / mid);
    }
    return cnt >= f + 1;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> f;
        for (int j = 0; j < n; j++)
        {
            cin >> radious[j];
        }
        double l = 0;
        double r = 1e14;
        double mid;
        for (int j = 0; j < 100; j++)
        {
            mid = (l + r) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << fixed << setprecision(6) << mid << endl;
    }
}
