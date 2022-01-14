#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n;
    cin >> n;
    long long arr[n];
    long long max = -1000000;
    long long current = 0;
    for (long i = 0; i < n; i++)
    {
        cin >> arr[i];
        current = current + arr[i];
        if (current > max && current % 2 == 0)
        {
            max = current;
        }
        else if (current < 0)
        {
            current = 0;
        }
    }
    cout << max << endl;
}