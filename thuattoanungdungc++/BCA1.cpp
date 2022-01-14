#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
int temp1, temp2;
int res = 10000;
int countIndex[11];
int Course[31];
int current = 0;
vector<vector<int>> listofposible;
vector<vector<int>> listofconflict;
void input()
{
    cin >> m >> n;
    listofposible.resize(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> temp1;
            listofposible[i].push_back(temp1);
        }
    }
    cin >> k;
    listofconflict.resize(n + 1);
    for (int i = 0; i < k; i++)
    {
        cin >> temp1 >> temp2;
        listofconflict[temp1].push_back(temp2);
        listofconflict[temp2].push_back(temp1);
    }
    for (int i = 0; i <= n; i++)
    {
        Course[i] = -1;
    }
}
bool check(int a, int i)
{
    int index = 0;
    for (int j = 0; j < listofposible[i].size(); j++)
    {
        if (listofposible[i].at(j) == a)
        {
            index++;
            //cout << "co the cho a " << a << " vao i " << i << endl;
        }
    }
    //cout<<index<<endl;
    if (index == 0)
    {
        //cout << "khong the cho a " << a << " vao i " << i << endl;
        return false;
    }
    for (int j = 0; j < listofconflict[a].size(); j++)
    {
        if (Course[listofconflict[a].at(j)] == i)
        {
            //   cout << "Conflict: " << i << "---Teachear " << i << "---voi mon " << a << endl;
            return false;
        }
    }
    return true;
}

int Solve(int a)
{
    //cout << "Xet mon " << a << ":\n";
    for (int i = 1; i <= m; i++)
    {
        //cout << "Xet teacher " << i << endl;
        if (check(a, i))
        {
            Course[a] = i;
            countIndex[i]++;
            //cout << i << " ok voi index = " << countIndex[i] <<"Tai a= "<<a<< endl;
            //cout<<current;
            if (a == n)
            {
                for (int q = 1; q <= a; q++)
                {
                    cout << "Mon " << q << " o vi tri " << Course[q] << endl;
                }
                cout << *max_element(countIndex, countIndex + n);
                current = *max_element(countIndex, countIndex + n);
                res = min(res, current);
                cout << "curren va res " << current << "---" << res << endl;
                cout<<"============================="<<endl;
                for(int i=1;i<=n;i++){
                    cout<< Course[i]<<" ";
                }
                cout<<"============================="<<endl;
            }
            else
            {
                Solve(a + 1);
            }
            Course[a] = -1;
            countIndex[i]--;
        }
    }
}
int main()
{
    input();
    // cout << "list of posible:" << endl;
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << "posible " << i << ": ";
    //     for (int j = 0; j < listofposible[i].size(); j++)
    //     {
    //         cout << listofposible[i].at(j) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "list of conflict:" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "conflict " << i << ": ";
    //     for (int j = 0; j < listofconflict[i].size(); j++)
    //     {
    //         cout << listofconflict[i].at(j) << " ";
    //     }
    //     cout << endl;
    // }
    Solve(1);
    cout << res;
    return 0;
}
