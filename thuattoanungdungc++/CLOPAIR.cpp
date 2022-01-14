#include <bits/stdc++.h>
using namespace std;
int n;
struct point
{
    int x;
    int y;
    int id;
} p[50000];
int firstPoint = 10000;
int secondPoint = 1000;
double res = 1000000;
bool cmp_x(point a, point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(point a, point b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
double distance(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Solve(int left, int right)
{
    if (right == left)
    {
        return;
    }
    int mid = (left + right) / 2;
    Solve(left, mid);
    Solve(mid + 1, right);

    vector<point> v;
    for (int i = left; i <= right; i++)
    {
        if (abs(p[mid].x - p[i].x) <= res)
        {
            v.push_back(p[i]);
        }
    }
    sort(v.begin(), v.end(), cmp_y);
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j].y - v[i].y >= res)
            {
                break;
            }
            double d = distance(v[i], v[j]);
            if (d < res)
            {
                firstPoint = v[i].id;
                secondPoint = v[j].id;
                res = d;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    sort(p, p + n, cmp_x);
    res = 1e9;
    Solve(0, n - 1);
    if(firstPoint>secondPoint){
        swap(firstPoint,secondPoint);
    }
    printf("%d %d %0.6f", firstPoint, secondPoint, res);
}
