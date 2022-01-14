#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vect;
void Solve(int k)
{
    if (vect[k] + 1 < vect[k + 1])
    {
        vect[k]++;
        //cout << "SOlve " << k << " co vecto " << vect[k] << endl;
        for (int j = k + 1; j < m; j++)
        {
            vect[j] = vect[k] + j - k;
        }
        for (int i = 0; i < m; i++)
        {
            cout << vect[i] << " ";
        }
        exit(0);
    }
    if (k > 0)
    {
        Solve(k - 1);
    }
    else
    {
        cout << "-1";
        exit(0);
    }
}
int main()
{
    cin >> n >> m;
    vect.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vect[i];
    }
    vect.push_back(n + 1);
    Solve(m - 1);
}