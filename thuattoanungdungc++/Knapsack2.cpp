#include <bits/stdc++.h>
using namespace std;
int n, limit;

struct data1
{
    int v, w;
};
data1 a[50];

int weightAll = 0;
bool cmp(data1 temp1, data1 temp2)
{
    return (float)temp1.v / temp1.w > (float)temp2.v / temp2.w;
}
int Solve(int i, int weight, int value)
{
    if (weight > limit)
        return 0;
    else if (i == n + 1 && weight <= limit)
        return value;
    else
    {
        int temp1 = Solve(i + 1, weight + a[i].w, a[i].v + value);
        int temp2 = Solve(i + 1, weight, value);
        return max(temp1, temp2);
    }
}
int main()
{
    cin >> n >> limit;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].v;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << Solve(1, 0, 0);
}
