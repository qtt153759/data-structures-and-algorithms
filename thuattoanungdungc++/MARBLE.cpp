/*21 11
4
10 4
6 2
7 5
15 10*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W, H, n;
    cin >> W >> H >> n;
    int w, h;
    int f[W + 1][H + 1];
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= H; j++)
        {
            f[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w >> h;
        f[w][h] = w * h;
    }
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            for (int i1 = 1; i1 < i; i1++)
            {
                int i2 = i - i1;
                f[i][j] = max(f[i][j], f[i1][j] + f[i2][j]);
            }
            for (int j1 = 1; j1 < j; j1++)
            {
                int j2 = j - j1;
                f[i][j] = max(f[i][j], f[i][j1] + f[i][j2]);
            }
            // printf("Voi i=%d  va j=%d  ta co f=%d\n", i, j, f[i][j]);
        }
    }
    cout << W * H - f[W][H] << endl;
}