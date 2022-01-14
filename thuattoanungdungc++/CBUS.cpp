// Luu y chon gioi han mang can than, lon->timelimited;
// nho qua thi bi runtimeerror neu vuot qua
//

#include <bits/stdc++.h>
using namespace std;
int n, k;
int t = 0;
int arr[23][23];
int minBus = 1000;
int minArr = 1000;
int distant = 0;
int already[23]; //dau tien nham thanh already[12]
int route[23];   //dau tien nham thanh route[12]
int res[23];     //dau tien nham thanh res[12]

bool check(int a, int i)
{
    if (i <= n && already[i] == false && t < k)
    {
        t++;

        return true;
    }
    if (i > n && already[i - n] == true && already[i] == false && t > 0)
    {
        t--;

        return true;
    }
    return false;
}
void Solve(int a)
{
    if (res[a - 1] + (2 * n - a + 1) * minArr < minBus - minArr)
    {

        for (int i = 1; i <= 2 * n; i++)
        {

            if (check(a, i))
            {
                route[a] = i;
                already[i] = true;
                res[a] = res[a - 1] + arr[route[a - 1]][i];

                if (a == 2 * n)
                {
                    if (arr[route[a]][0] != 0)
                    {

                        minBus = min(minBus, res[a] + arr[route[a]][0]);
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
                else
                {
                    t++;
                }

                already[i] = false;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> arr[i][j];
            if (i != j)
                minArr = min(arr[i][j], minArr);
        }
    }
    already[0] = true;
    route[0] = 0;
    res[0] = 0;
    Solve(1);
    cout << minBus << endl;
    return 0;
}
