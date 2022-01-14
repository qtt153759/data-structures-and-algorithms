#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int tmp1[n + 1];
    int tmp2[m + 1];
    int res[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp1[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp2[i];
    }
    for (int i = 0; i <= n; i++)
    {
        res[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        res[0][i] = 0;
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (tmp1[i] == tmp2[j])
            {
                res[i][j] = res[i - 1][j - 1] + 1;
            }
            else
            {
                tmp = max(res[i][j - 1], res[i - 1][j]);
                res[i][j] = tmp;
            }
            //cout << " tai " << i << " " << j << "->" << res[i][j] << endl;
        }
    }
    cout << res[n][m];
}