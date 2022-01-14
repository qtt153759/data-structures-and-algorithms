#include <bits/stdc++.h>
using namespace std;
int n, m, a;
vector<int> vect;
int index = 0;
void Solve(int k)
{
    if (vect[k] + 1 < vect[k + 1])
    {
        vect[k]++;
        index++;
        // cout << "\nindex=" << index << endl;
        for (int j = k + 1; j < m; j++)
        {
            vect[j] = vect[k] + j - k;
        }
        // for (int i = 0; i < m; i++)
        // {
        //     cout << vect[i] << " ";
        // }
    }
    if (k > 0)
    {
        Solve(k - 1);
    }
    if (k == 0)
    {
        cout << "index" << index << endl;
        if (index < a)
        {
            cout << -1;
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                cout << vect[i] << " ";
            }
        }
        exit(0);
    }
}
int main()
{
    cin >> n >> m >> a;
    vect.resize(m);
    for (int i = 0; i < m; i++)
    {
        vect[i] = i + 1;
    }
    index++;
    vect.push_back(n + 1);
    do
    {
        Solve(m - 1);
    } while (index == a);
    for (int i = 0; i < m; i++)
    {
        cout << vect[i] << " ";
    }
}
