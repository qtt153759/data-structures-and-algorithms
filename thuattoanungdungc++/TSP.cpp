#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[21][21];
bool check[21];
vector<int> vect;
int res = 0;
int minTsp = 1000000;
int minArr = 1000000;
int Solve(int k)
{
    if (res + (n - k + 2) * minArr < minTsp)
    {
        for (int i = 2; i <= n; i++)
        {
            if (check[i] == false && arr[vect.back()][i] != 0)
            {
                check[i] = true;
                res = res + arr[vect.back()][i];
                vect.push_back(i);
                if (k == n)
                {
                    if (arr[i][1] != 0)
                    {

                        minTsp = min(minTsp, res + arr[i][1]);
                    }
                }
                else
                {
                    Solve(k + 1);
                }
                vect.pop_back();
                res = res - arr[vect.back()][i];
                check[i] = false;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (c < minArr)
        {
            minArr = c;
        }
        arr[a][b] = c;
    }
    check[1] = true;
    vect.push_back(1);
    Solve(2);
    cout << minTsp;
}
//luu y vector.back() va vector.front()
//de nhanh can o dau cx anh huong toc do thuat toa