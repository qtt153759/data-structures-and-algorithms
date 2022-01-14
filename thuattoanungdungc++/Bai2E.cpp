#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    map<int, pair<int, int>> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        m[i].first = x;
        m[i].second = 0;
    }
    m[0].first = m[1].first;
    m[n + 1].first = m[n].first;
    int index = 1;
    for (int i = 1; i <= n; i = i + 2)
    {
        if (m[i].first != m[i - 1].first && m[i].first != m[i + 1].first)
        {
            m[i].second = 2;
        }
        else if (m[i].first == m[i - 1].first && m[i].first == m[i + 1].first)
        {
            m[i].second = 0;
        }
        else
        {
            m[i].second = 1;
        }
        index += m[i].second;
    }
    int t;
    cin >> t;
    int a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        m[a].second = 0;
        if (m[a].first != m[a + 1].first && a < n)
        {
            m[a].second++;
        }
        if (m[a].first != m[a - 1].first && a > 1)
        {
            m[a].second++;
        }
        //  cout << index << "before" << m[a].second << endl;
        index -= m[a].second;
        // cout << index << "after\n";
        // if(a==1){
        //     m[0].first=b;
        // }else if(a==n){
        //     m[n+1].first=b;
        // }
        m[a].first = b;
        m[a].second = 0;
        if (m[a].first != m[a + 1].first && a < n)
        {
            m[a].second++;
        }
        if (m[a].first != m[a - 1].first && a > 1)
        {
            m[a].second++;
        }
        index += m[a].second;
        cout << index << endl;
    }
}
