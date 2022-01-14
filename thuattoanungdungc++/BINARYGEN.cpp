#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a = 1;
    string str;
    int res = 0;
    cin >> n;
    getchar();
    getline(cin, str);
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            res = res + a;
            //cout << "Voi a=" << a << " -> res=" << res << endl;
        }
        a = a * 2;
    }
    res++;
    if (res == a)
    {
        cout << -1;
    }
    else
    {
        //  cout << res;
        for (int i = n - 1; i >= 0; i--)
        {
            if (res % 2 == 1)
            {
                str[i] = '1';
            }
            else
            {
                str[i] = '0';
            }
            res = res / 2;
        }
        cout << str;
    }
}