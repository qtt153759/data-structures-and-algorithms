#include <bits/stdc++.h>
using namespace std;
int Solve(vector<int> vect, int maxVt, int n, int b)
{
    int res = -1;
    int maxLeft = 0;
    int maxRight = n - 1;
    for (int i = 1; i < maxVt; i++)
    {
        if (vect[maxLeft] < vect[i])
        {
            maxLeft = i;
        }

        else
        {
            if (vect[maxLeft] - vect[i] >= b && vect[maxVt] - vect[i] >= b)
            {
                res = max(res, vect[maxLeft] + vect[maxVt] - 2 * vect[i]);
            }
        }
    }

    for (int i = n - 2; i > maxVt; i--)
    {
        if (vect[maxRight] < vect[i])
        {
            maxRight = i;
        }
        else
        {
            if (vect[maxRight] - vect[i] >= b && vect[maxVt] - vect[i] >= b)
            {
                res = max(res, vect[maxRight] + vect[maxVt] - 2 * vect[i]);
            }
        }
    }
    return res;
}
int main()
{
    int n, b;
    cin >> n >> b;
    int k = 0;
    int maxVt = 0;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vect.push_back(k);
        if (k > vect[maxVt])
        {
            maxVt = i;
        }
    }
    // cout << "\nMax=" << max << " o vi tri " << maxVt;

    cout << Solve(vect, maxVt, n, b);
}
