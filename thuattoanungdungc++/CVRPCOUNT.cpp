#include <bits/stdc++.h>
using namespace std;
int n, k, q;
int d[11];
int volume[6];
vector<vector<int> > route;
int index = 0;
void solution()
{
    int count = 1;
    for (int i = 1; i <= k; i++)
    {
        if (route[i].size() == 0)
        {
            return;
        }
        else
        {
            for (int j = 1; j <= route[i].size(); j++)
            {
                count = count * j;
            }
        }
    }
    index = index + count;
        for (int i = 1; i <= k; i++)
        {
              cout << "route " << i << " : ";
            for (int j = 0; j < route[i].size(); j++)
            {
                cout << route[i].at(j) << " ";
            }
            cout << endl;
        }
}
int Solve(int a)
{
    for (int i = 1; i <= k; i++)
    {
        //   cout << "Xet " << a << " va " << i << endl;
        if (volume[i] + d[a] <= q)
        {
            //   cout << "route " << i << " push " << a << endl;
            route[i].push_back(a);
            volume[i] += d[a];
            if (a == n)
            {
                solution();
            }
            else
            {
                Solve(a + 1);
            }
            route[i].pop_back();
            volume[i] -= d[a];
            //     cout << "route " << i << " pop " << a << endl;
        }
    }
}
int main()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    int t = 1;
    for (int i = 1; i <= k; i++)
    {
        t = t * i;
    }
    route.resize(k + 1);
    Solve(1);
    cout << index / t;
}
