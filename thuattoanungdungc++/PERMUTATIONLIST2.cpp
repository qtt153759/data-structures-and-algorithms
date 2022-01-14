#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    do
    {
        index++;
    } while (index < k && next_permutation(arr, arr + n));
    if (index == k)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }
}