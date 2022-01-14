#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    int arr[n];
    int res[n];
    int atTheend = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int max_in_l = 0;
        for (int j = i - l2; j <= i - l1; j++)
        {
            if (j >= 0)
            {
                max_in_l = max(max_in_l, res[j]);
            }
        }
        res[i] = arr[i] + max_in_l;
        atTheend = max(res[i], atTheend);
    }
    cout << atTheend << endl;
}