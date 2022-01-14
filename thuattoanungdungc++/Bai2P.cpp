#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int arr[n][m];
    int minStep = m * n;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    Q.push({x - 1, y - 1});
    arr[x - 1][y - 1] = 1;
    while (!Q.empty())
    {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        //cout << "xet " << a << "-" << b << endl;
        if (a == 0 || a == n - 1 || b == 0 || b == m - 1)
        {
            minStep = arr[a][b];
            break; //luc dau toi khong co continue
        }
        if (arr[a + 1][b] == 0) //(luc dau no la ntn arr[a + 1][b] == 0&&a<n-1) ca 3 cai dk duoi nua
        {
            Q.push({a + 1, b});
            arr[a + 1][b] = arr[a][b] + 1;
            //cout << "push (" << a + 1 << "-" << b << ") voi arr =" << arr[a + 1][b] << endl;
        }
        if (arr[a - 1][b] == 0)
        {
            Q.push({a - 1, b});
            arr[a - 1][b] = arr[a][b] + 1;
            // cout << "push (" << a - 1 << "-" << b << ") voi arr =" << arr[a - 1][b] << endl;
        }
        if (arr[a][b + 1] == 0)
        {
            Q.push({a, b + 1});
            arr[a][b + 1] = arr[a][b] + 1;
            // cout << "push (" << a << "-" << b + 1 << ") voi arr =" << arr[a][b + 1] << endl;
        }
        if (arr[a][b - 1] == 0)
        {
            Q.push({a, b - 1});
            arr[a][b - 1] = arr[a][b] + 1;
            // cout << "push (" << a << "-" << b - 1 << ") voi arr =" << arr[a][b - 1] << endl;
        }
    }
    cout << minStep << endl;
}
