#include <bits/stdc++.h>
using namespace std;
int n, m;
int credit[17];
vector<vector<int>> period;
int arr[17][17];
int visited[17];
int index[17];
int res = 1000;
bool check(int a, int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (arr[a][j] == 1 && visited[j] != 0 && visited[j] > i)
        {
            //cout << "false tai a " << a << " va j " << j << endl;
            return false;
        }
    }
    return true;
}
void Solution()
{
    int currentMax = 0;
    for (int i = 1; i <= m; i++)
    {
        //cout << "tai period " << i << " : ";
        for (int j = 0; j < period[i].size(); j++)
        {
            //cout << period[i].at(j) << " ";
        }
    }
    for (int i = 1; i <= m; i++)
    {
        currentMax = max(currentMax, index[i]);
    }
    res = min(res, currentMax);
    //cout << "\nUpdate res=" << res << endl;
}
void Solve(int a)
{
    for (int i = 1; i <= m; i++)
    {
        //cout << "xet a " << a << " va i " << i << endl;
        if (check(a, i))
        {
            visited[a] = i;
            period[i].push_back(a);
            index[i] = index[i] + credit[a];
            //cout << "push " << a << " vao index " << i << " update= " << index[i] << endl;
            if (a == n)
            {
                Solution();
            }
            else
            {
                if (index[i] < res)
                {
                    Solve(a + 1);
                }
            }
            index[i] = index[i] - credit[a];
            visited[a] = 0;
            period[i].pop_back();
            //cout << "pop " << a << " khoi index " << i << " update= " << index[i] << endl;
        }
    }
}
int main()
{
    cin >> n >> m;
    period.resize(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> credit[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    Solve(1);
    cout << res << endl;
}
