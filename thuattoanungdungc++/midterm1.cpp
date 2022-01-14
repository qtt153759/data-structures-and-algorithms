#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    int tmp = 0;
    pair<int, string> max;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        getchar();
        cin >> tmp;
        if (tmp > max.first)
        {
            max.first = tmp;
            max.second = str;
        }
    }
    cout << max.second;
}
