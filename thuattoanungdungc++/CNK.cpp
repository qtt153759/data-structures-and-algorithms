#include <bits/stdc++.h>
using namespace std;
int t, n, k, m;
int arr[100];
int cnk = 0;
int main()
{
    unsigned long long res;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k >> m;
        for (int j = 0; j < k; j++)
        {
            arr[j] = j + 1;
        }
        cnk++;
        int tmp = k - 1;
        arr[k] = n + 1;
        while (tmp >= 0)
        {
            if (arr[tmp] + 1 < arr[tmp + 1])
            {
                arr[tmp]++;
                for (int j = tmp + 1; j < k; j++)
                {
                    arr[j] = arr[j - 1] + 1;
                }
                tmp = k - 1;
                cnk++;
                //cout << "\nxet cnk=" << cnk << ": ";
                // for (int j = 0; j < k; j++)
                // {
                //     cout << arr[j] << " ";
                // }
            }
            else
            {
                tmp--;
            }
        }
        cout << cnk % m << endl;
    }
}
