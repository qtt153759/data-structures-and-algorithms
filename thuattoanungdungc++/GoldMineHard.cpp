#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, l1, l2;
int a[N];
int f[N];
int result = 0;
int main()
{
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        if (i <= l1)
        {
            f[i] = a[i];
        }
        else
        {
            while (!q.empty() && q.front() < i - l2)
            {
                q.pop_front();
            }
            while (!q.empty() && f[q.back()] < f[i - l1])
            {
                q.pop_back();
            }
            q.push_back(i - l1);
            f[i] = a[i] + f[q.front()];
        }
        if (result < f[i])
        {
            result = f[i];
        }
    }
    cout << result;
}