#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> vect;
int index = 0;
void Solve(int a)
{
    for (int i = vect[a - 1] + 1; i <= n; i++)
    {
        vect[a] = i;
        //cout << "vect a=i " << a << "--" << i << endl;
        if (a == m)
        {
            index++;
            //cout << "\nindex " << index << ": ";
            if (index == k)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << vect[j] << " ";
                }
                exit(0);
            }
        }
        else
        {
            Solve(a + 1);
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    vect.resize(m + 1);
    vect[0] = 0;

    Solve(1);
    cout << -1;
}