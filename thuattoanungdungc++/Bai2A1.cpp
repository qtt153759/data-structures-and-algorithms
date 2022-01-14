#include <bits/stdc++.h>
using namespace std;
long long Solve(long long arr[], long long n)
{
    vector<long long> L(n, -1);
    vector<long long> R(n, n);
    stack<long long> pstack;
    pstack.push(-1);
    long long maxArea = 0;
    long long currentArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!pstack.empty() && pstack.top() != -1 && arr[pstack.top()] > arr[i])
        {
            R[pstack.top()] = i;
            //cout << "\npop " << pstack.top();
            pstack.pop();
        }
        if (arr[i] == arr[pstack.top()])
        {
            L[i] = L[pstack.top()];
        }
        else
        {
            L[i] = pstack.top();
        }
        pstack.push(i);
        // cout << "\npush " << i;
    }
    for (int i = 0; i < n; i++)
    {
        currentArea = arr[i] * (R[i] - L[i] - 1);
        //cout << "current-l-r-i:" << currentArea << " " << L[i] << " " << R[i] << " " << i << endl;
        maxArea = max(currentArea, maxArea);
    }
    return maxArea;
}
int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    do
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << Solve(arr, n) << endl;
        cin >> n;
    } while (n > 0);
}
