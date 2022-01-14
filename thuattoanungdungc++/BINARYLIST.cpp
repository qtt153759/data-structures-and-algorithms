#include <bits/stdc++.h>
using namespace std;
int n, k, i;
int countk = 0;
int index = 0;
void Try(int h, int arr[])
{
    for (int j = 0; j <= 1; j++)
    {
        //   cout << "xet j" << j << " tai h " << h << endl;
        if (j == 1)
        {
            index = 0;
            arr[h] = j;
            // cout << "push j" << j << " vao h " << h << endl;
            if (h == n - 1)
            {
                countk++;
                // cout << "\n countk=" << countk << endl;
                if (countk == k)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << arr[j] << " ";
                    }
                    exit(0);
                }
            }
            else
            {
                Try(h + 1, arr);
            }
            // cout << "out j" << j << " tai h " << h << endl;
        }
        else if ((j == 0 && index != i - 1))
        {
            index++;
            arr[h] = j;
            // cout << "push j" << j << " vao h " << h << endl;
            if (h == n - 1)
            {
                countk++;
                // cout << "\n countk=" << countk << endl;
                if (countk == k)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << arr[j] << " ";
                    }
                    exit(0);
                }
            }
            else
            {
                Try(h + 1, arr);
            }
        }
    }
}
int main()
{
    cin >> n >> k >> i;
    int arr[n];
    Try(0, arr);
    cout << -1;
}
