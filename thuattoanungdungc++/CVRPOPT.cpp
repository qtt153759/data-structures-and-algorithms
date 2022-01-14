#include <bits/stdc++.h>
using namespace std;
int n, k, q;
int request[13];
int d[13][13];
int weight[6];
vector<vector<int> > truck;
int result = 10000;
int res[6];
void Solution()
{
    int restmp = 0;
    for (int i = 1; i <= k; i++)
    {
        int temp[truck[i].size()];
        //cout << "xet solution " << i << ":";
        for (int j = 0; j < truck[i].size(); j++)
        {
            temp[j] = truck[i].at(j);
            //cout << temp[j] << " ";
        }
        sort(temp, temp + truck[i].size());
        //cout << "\nsize " << truck[i].size() << endl;
        do
        {
            //cout << "\n Xet tap hoan vi:";
            int count = 0;
            for (int j = 1; j < truck[i].size(); j++)
            {
                //cout << temp[j] << " ";
                count = d[temp[j - 1]][temp[j]] + count;
            }
            // //cout << endl;
            count = count + d[temp[truck[i].size() - 1]][0];
            res[i] = min(res[i], count);
            //cout << "\nupdate res" << i << " la " << res[i] << endl;

        } while (next_permutation(temp + 1, temp + truck[i].size()));
        restmp = res[i] + restmp;
        res[i] = 1000;
        //cout << "update restmp:" << restmp << endl;
    }
    result = min(restmp, result);
    //cout << "sum result: " << result << endl;
}
void Solve(int a)
{
    for (int i = 1; i <= k; i++)
    {
        //cout << "xet " << a << " vao truck " << i << endl;
        if (weight[i] + request[a] <= q)
        {
            truck[i].push_back(a);
            weight[i] = weight[i] + request[a];
            //cout << "push " << a << " vao truck " << i << " voi weight " << weight[i] << endl;
            if (a == n)
            {
                Solution();
            }
            else
            {
                Solve(a + 1);
            }
            weight[i] = weight[i] - request[a];
            truck[i].pop_back();
            //cout << "pop " << a << " khoi truck " << i << " voi weight " << weight[i] << endl;
        }
    }
}
int main()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> request[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    truck.resize(k + 1);
    for (int i = 1; i <= k; i++)
    {
        truck[i].push_back(0);
        res[i] = 1000;
    }
    Solve(1);
    cout << result << endl;
}
