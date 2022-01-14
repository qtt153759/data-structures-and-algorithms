#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s[100];
    int t[100];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
    }
    int m = *max_element(t + 1, t + n + 1);
    int best[100] = {0};
    int dp[100] = {0};
    // for (int i = 0; i < 100; i++)
    // {
    //     best[i] = 0;
    //     dp[i] = 0;
    // }

    for (int i = 1; i <= n; i++)
    {
        best[t[i]] = max(best[t[i]], t[i] - s[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        dp[i] = max(dp[i - 1], best[i]);
        printf("voi %d=%d\n", i, dp[i]);
    }
    int kq = 0;
    for (int j = 1; j <= n; j++)
    {
        printf("voi %d=%d   trong do  %d   %d  %d\n", j, dp[s[j] - 1] + t[j] - s[j], dp[s[j] - 1], t[j], s[j]);
        kq = max(kq, dp[s[j] - 1] + t[j] - s[j]);
    }
    cout << kq;
}