#include <bits/stdc++.h>
using namespace std;
int n, k;
int t = 0;
int arr[2 * 11 + 1][2 * 11 + 1];
int minBus = 100000;
int minArr = 100000;
int already[23];
int route[23];
int res[23];
bool check(int a, int i)
{
    if (i <= n && already[i] == false && t < k)
    {
        t++;
        //cout << "check i=" << i << "voi t " << t << endl;
        return true;
    }
    if (i > n && already[i - n] == true && already[i] == false && t > 0)
    {
        t--;
        //cout << "check i=" << i << "voi t " << t << endl;

        return true;
    }
    return false;
}
void Solve(int a)
{
    //cout << "vao " << a << endl;
    if (res[a - 1] + minArr * (2 * n - a + 1) < minBus - minArr)
    {
        //index1++;
        //cout << "tam nhin ok vs " << res[a - 1] << "+" << minArr * (n - k + 1) << " so voi " << minBus - minArr << endl;
        for (int i = 1; i <= 2 * n; i++)
        {
            //cout << "tai " << a << " xet " << i << endl;
            if (check(a, i))
            {
                already[i] = true;
                route[a] = i;
                res[a] = res[a - 1] + arr[route[a - 1]][i];
                //cout << "xet res cua " << a << " la " << res[a] << endl;
                if (a == 2 * n)
                {
                    if (arr[route[a]][0] != 0)
                    {
                        // for (int j = 0; j <= n * 2; j++)
                        // {
                        //     //cout << "(" << route[j] << "-" << res[j] << ")"
                        //     << ",";
                        // }
                        minBus = min(minBus, res[a] + arr[route[a]][0]);
                        //cout << "tai " << a << "ta co min bus " << minBus << " va res+routecuoi " << res[a] + arr[route[a]][0] << endl;
                    }
                }
                else
                {
                    Solve(a + 1);
                }
                if (i <= n)
                {
                    t--;
                }
                else if (i > n)
                {
                    t++;
                }
                //cout << "out " << i << " voi t=" << t << endl;
                already[i] = false;
            }
        }
    }
    // else
    // {
    //     //cout << "loai " << ++index<<" xo voi chon "<<index1 << endl;
    // }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
                minArr = min(arr[i][j], minArr);
        }
    }
    already[0] = true;
    route[0] = 0;
    res[0] = 0;
    Solve(1);
    cout << minBus << endl;
}
