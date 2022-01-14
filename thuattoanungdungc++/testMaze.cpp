#include <bits/stdc++.h>

using namespace std;

int step = 0;
int m, n, x, y;
bool a[1000][1000];

struct state
{
    int x;
    int y;
    int dis;
    //    state(int a, int b, int c)
    //    {
    //        x = a;
    //        y = b;
    //        dis = c;
    //    }
};

int solve()
{

    return -1;
}

int main()
{
    int minMaze = 100000;
    cin >> m >> n >> x >> y;
    // x++;
    // y++;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            a[i][j] = false;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int moveX[] = {0, 0, -1, 1};
    int moveY[] = {1, -1, 0, 0};
    queue<state> q;
    state state0 = {x, y, 0};
    q.push(state0);
    a[x][y] = true;

    while (!q.empty())
    {
        state stateQ = q.front();
        cout << "xet " << stateQ.x << "-" << stateQ.y << endl;
        q.pop();

        if (stateQ.x == 1 || stateQ.y == 1 || stateQ.x == m || stateQ.y == n)
        {
            minMaze = stateQ.dis;
            continue;
        }

        int xi = stateQ.x;
        int yi = stateQ.y;
        cout << "xet " << xi << "-" << yi << endl;
        if (a[xi + 1][yi] == false)
        {
            int z = stateQ.dis + 1;
            q.push({xi + 1, yi, z});
            a[xi + 1][yi] = true;
            cout << "push (" << xi + 1 << "-" << yi << ") voi arr =" << a[xi + 1][yi] << endl;
        }
        if (a[xi][yi + 1] == false)
        {
            int z = stateQ.dis + 1;
            q.push({xi, yi + 1, z});
            a[xi][yi + 1] = true;
            cout << "push (" << xi << "-" << yi + 1 << ") voi arr =" << a[xi][yi + 1] << endl;
        }
        if (a[xi - 1][yi] == false)
        {
            int z = stateQ.dis + 1;
            q.push({xi - 1, yi, z});
            a[xi - 1][yi] = true;
            cout << "push (" << xi - 1 << "-" << yi << ") voi arr =" << a[xi - 1][yi] << endl;
        }
        if (a[xi][yi - 1] == false)
        {
            int z = stateQ.dis + 1;
            q.push({xi, yi - 1, z});
            a[xi][yi - 1] = true;
            cout << "push (" << xi << "-" << yi - 1 << ") voi arr =" << a[xi][yi - 1] << endl;
        }
    }
    cout << minMaze + 1;

    return 0;
}
