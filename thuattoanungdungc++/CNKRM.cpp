#include <bits/stdc++.h>
using namespace std;

int n, k;
long double multiple(int a, int b)
{
    long double tmp = 1;
    for (int i = 1; i <= b; i++)
    {
        tmp = tmp * (a - i + 1);
         cout << "tich tmp  " << a - i + 1 << " = " << tmp << endl;
        tmp = tmp / (b - i + 1);
        cout << "thuong tmp  " << b - i + 1 << " = " << tmp << endl;
    }
    return tmp;
}
int main()
{
    cin >> k >> n;
    unsigned long long res = multiple(n, k);
    cout << res << endl;
}
