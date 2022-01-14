#include <bits/stdc++.h>
using namespace std;
int n, k1, k2;
int arr[1000];
unsigned long long res = 0;
unsigned long long e1 = (1e9 + 7);
bool check(int a, int i)
{
    if (a == 1)
    {
        if (i == 1)
        {
            arr[1] = 1;
        }
        return true;
    }
    if (i == 0)
    {
        if (arr[a - 1] == 0)
        {
            return false;
        }
        else if (arr[a - 1] < k1)
        {
            return false;
        }
        else if (arr[a - 1] >= k1)
        {
            arr[a] = 0;
            return true;
        }
    }
    else if (i == 1)
    {
        if (arr[a - 1] >= k2)
        {
            return false;
        }
        else if (arr[a - 1] == 0 && n - a + 1 < k1)//them cai dieu kien nay giam toc do may cai cuoi
        {//1 kieu nhanh can trong ham check
            return false;
        }
        else if (arr[a - 1] < k2)
        {
            arr[a] = arr[a - 1] + 1;
            return true;
        }
    }
}
void Solve(int a)
{
    for (int i = 0; i <= 1; i++)
    {
        if (check(a, i))
        {
            // cout << "xet a va i" << a << "  - " << i << endl;
            if (a == n)
            {
                if ((arr[a] >= k1 && arr[a] <= k2) || arr[a] == 0)
                {

                    res++;
                    // cout << "update res " << res << " : ";
                    // for (int j = 1; j <= n; j++)
                    // {
                    //     cout << arr[j] << " ";
                    // }
                    // cout << endl;
                }
            }
            else
            {
                Solve(a + 1);
            }
            // cout << "thoat a va i" << a << "  - " << i << endl;
        }
    }
}
int main()
{
    cin >> n >> k1 >> k2;
    Solve(1);
    cout << res % e1 << endl;
}
