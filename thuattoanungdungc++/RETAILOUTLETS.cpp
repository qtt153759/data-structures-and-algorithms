#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[101][501];
int a[101];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int x = a[i]; x <= j; x += a[i])
            {
                arr[i][j] += arr[i - 1][j - x];
                arr[i][j] %= 1000000007;
            }
        }
    }
    cout << arr[n][m];
}