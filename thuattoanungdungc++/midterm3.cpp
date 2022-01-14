#include <bits/stdc++.h>
using namespace std;
long long a, b;
vector<long long> arr;
long long Solve(int k, int res, int discuss)
{
    long long discuss1 = discuss % 10;
    vector<int> vect;
    // cout << "xet tai " << k << " res " << res << " discuss " << discuss << "va discuss1 " << discuss1 << endl;
    for (int i = 0; i <= 9; i++)
    {
        long long tmp = pow(discuss1, i);
        if (res % 10 == tmp % 10)
        {

            vect.push_back(i);
            // cout << "ta co i=" << i << "thoa man" << endl;
        }
    }
    for (int i = 0; i < vect.size(); i++)
    {
        int res1 = res - pow(discuss1, vect[i]);
        //  cout << "res sau khi tru pow i" << i << " con lai" << res1 << endl;
        arr[k] = vect[i];
        if (res1 == 0)
        {
            //cout << "ket qua" << arr.size() << endl;
            for (int j = 1; j < arr.size(); j++)
            {
                cout << arr[j] << " ";
            }
            //cout << "end gmae";
            exit(0);
        }

        else
        {
            res1 = res1 / 10;
            if (res1 != 0)
            {
                Solve(k - 1, res1, discuss / 10);
            }
        }
    }
}
int main()
{
    cin >> a >> b;
    int c = a;
    int index = 0;
    while (c != 0)
    {
        c = c / 10;
        index++;
    }
    //cout << index;
    arr.resize(index + 1);
    //cout << "arr size" << arr.size() << endl;
    Solve(index, b, a);
}
