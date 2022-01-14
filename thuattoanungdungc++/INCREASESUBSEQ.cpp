#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int max = 0;
    cin >> n;
    int arr[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && res[j] + 1 > res[i])
            {
                res[i] = res[j] + 1;
            }
        }
        if (res[i] > max)
        {
            max = res[i];
        }
    }
    cout << max << endl;
}