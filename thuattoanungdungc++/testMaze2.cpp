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
};

int solve()
{
    if (x <= 0 || y <= 0 || x >= m + 1 || y >= n + 1)
        return -1;

    if (!a[x][y])
    {
        int moveX[] = {0, 0, -1, 1};
        int moveY[] = {1, -1, 0, 0};
        queue<state> q;

        state state0 = {x, y, 0};
        q.push(state0);
        a[x][y] = true;

        while (!q.empty())
        {
            state stateQ = q.front();

            for (int i = 0; i < 4; i++)
            {
                int xi = stateQ.x + moveX[i];
                int yi = stateQ.y + moveY[i];

                if (!a[xi][yi])
                {
                    state statei = {xi, yi, stateQ.dis + 1};
                    q.push(statei);
                    a[xi][yi] = true;

                    if (xi == 0 || yi == 0 || xi == m + 1 || yi == n + 1)
                        return statei.dis;
                }
            }
            q.pop();
        }
    }

    return -1;
}

int main()
{
    cin >> m >> n >> x >> y;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cout << solve();

    return 0;
}
