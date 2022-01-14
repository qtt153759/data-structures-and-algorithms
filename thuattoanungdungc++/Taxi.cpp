#include <bits/stdc++.h>
using namespace std;
int n;
int res = 0;
int cmin = 1000000;
vector<int> vect;
int check[12];
int arr[2 * 11 + 1][2 * 11 + 1];
int Taxi = 10000000;
int Solve(int k)
{
    //  cout << "\nXet k=" << k << endl;
    if (res + 2 * cmin * (n - k + 1) < Taxi - cmin)
    {
        for (int i = 1; i <= n; i++)
        {
            //   cout << "Xet i=" << i << endl;
            if (check[i] == false && arr[vect.back()][i] != 0)
            {
                res = res + arr[vect.back()][i] + arr[i][i + n];
                //    cout << i << "ok va res moi la" << res << endl;
                vect.push_back(i);
                vect.push_back(i + n);
                check[i] = true;
                if (k == n)
                {
                    if (arr[i + n][0] != 0)
                    {
                        Taxi = min(Taxi, res + arr[i + n][0]);
                    }
                }
                else
                {
                    Solve(k + 1);
                }
                vect.pop_back();
                vect.pop_back();
                check[i] = false;
                //luu y khong can check[i+n]
                res = res - arr[vect.back()][i] - arr[i][i + n];
                // cout << "out ra o" << i << " va res tra ve " << res << endl;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> arr[i][j];
            if (i != j)
            {
                cmin = min(cmin, arr[i][j]);
            }
        }
    }
    //vect.resize(n);
    vect.push_back(0);
    check[0] = true;
    Solve(1);
    cout << Taxi;
}