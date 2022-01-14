#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long Solve(vector<pair<int, int>> vect, int n, int m)
{
    sort(vect.begin(), vect.end(), greater<pair<int, int>>());
    long long num = 0;
    long long remainder = 0;
    long long total_distant = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        // cout << "xet " << vect[i].first << "+" << vect[i].second << endl;
        num = vect[i].second / m;
        if (num * m - vect[i].second < 0)
        {
            num++;
            remainder = m - vect[i].second % m;
        }
        else
        {
            remainder = 0;
        }
        int j = i + 1;
        while (remainder > 0 && j < vect.size())
        {
            if (remainder <= vect[j].second)
            {
                vect[j].second -= remainder;
                remainder = 0;
            }
            else if (remainder > vect[j].second)
            {
                remainder -= vect[j].second;
                vect[j].second = 0;
                j++;
            }
        }
        total_distant += 2 * num * vect[i].first;
        //  cout << "\ndistant o " << i << " la " << num * vect[i].first << " va total la:" << total_distant << endl;
    }
    return total_distant;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<pair<int, int>> L, R;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> y;
        if (x > 0)
        {
            R.push_back({x, y});
        }
        else if (x < 0)
        {
            L.push_back({-x, y});
        }
    }
    long long res = Solve(L, n, m) + Solve(R, n, m);
    cout << res;
}
