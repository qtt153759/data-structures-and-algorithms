#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vect;
int main()
{
    int index = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    next_permutation(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            index++;
        }
    }
    if (index == n)
    {
        cout << -1;//vd n=5 vs 1 2 3 4 5 ->next-permutation=-1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}