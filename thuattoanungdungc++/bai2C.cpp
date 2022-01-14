#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        int l, c;
        int a, b;

        vector<pair<int, int>> prev, last;
        map<pair<int, int>, int> m;
        int maxLC = 0;
        cin >> l >> c;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int z;
                cin >> z;
                if (z)
                {
                    prev.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int z;
                cin >> z;
                if (z)
                {
                    last.push_back({i, j});
                }
            }
        }
        int lensPre = prev.size();
        int lensLast = last.size();
        for (int i = 0; i < lensLast; i++)
        {
            for (int j = 0; j < prev.size(); j++)
            {
                a = last[i].first - prev[j].first + 1000;
                b = last[i].second - prev[j].second + 1000;
                m[{a, b}]++;
                maxLC = max(m[{a, b}], maxLC);
            }
        }
        cout << maxLC << endl; //vi thieu chu endl ma tu 60->20
        n--;
    }
    return 0;
}
