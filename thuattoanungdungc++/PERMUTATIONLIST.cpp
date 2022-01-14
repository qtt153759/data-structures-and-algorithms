#include <bits/stdc++.h>
using namespace std;
int n, k;
bool check[10000];
int arr[10000];
int index = 0;
void Try(int a)
{
    //cout << "xet a=" << a << endl;
    if (index == k)
    {
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        //  cout << "xet i tai a " << i << "---" << a << endl;
        if (index == k)
        {
            return;
        }
        if (check[i] == false)
        {
            check[i] = true;
            arr[a] = i;
            if (a == n)
            {
                index++;
                //    cout << "tai " << index << endl;
                // for (int j = 1; j <= n; j++)
                // {
                //     cout << arr[j] << " ";
                // }
                // cout << endl;
            }
            else
            {
                Try(a + 1);
            }
            check[i] = false;
        }
    }
}
int main()
{
    cin >> n >> k;
    Try(1);
    if (index == k)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[j] << " ";
        }
    }
    else
    {
        cout << -1;
    }
}