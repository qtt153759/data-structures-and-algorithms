#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c;
    cin >> n >> c;
    int a, b;

    vector<pair<int, int> > item;
    item.push_back({0, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        item.push_back({a, b});
        //  cout << "Push a,b" << a << "-" << b << endl;
    }
    sort(item.begin(), item.end());
    int arr[c + 1][item.size()];
    for (int i = 0; i <= c; i++)
    {
        //   cout << "c= " << c << endl;
        for (int j = 0; j < item.size(); j++)
        {
            //  cout << "\n xet i va item " << i << "---" << j << "---" << item[j].first << endl;
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
                //    cout << "if item size va j" << item.size() << "   " << j << endl;
            }
            else if (i < item[j].first)
            {
                arr[i][j] = arr[i][j - 1];
                //  cout << "else if item size va j" << item.size() << "   " << j << endl;
            }
            else
            {
                // arr[i][j] = max(arr[i][j - 1], item[j].second + arr[i - item[j].first][j - 1]);
                //   int value = item[j].second;
                //   int weight = item[j].first;
                //   cout << "else item size va j" << item.size() << "   " << j << endl;
                arr[i][j] = max(arr[i][j - 1], item[j].second + arr[i - item[j].first][j - 1]);
                //   cout << "else item size va j" << item.size() << "   " << j << endl;
            }
            //  cout << "item size va j" << item.size() << "   " << j << endl;
            if (i == c && j == item.size() - 1)
            {
                //  cout << "\ncout" << endl;
            }
            //cout << arr[i][j] << "-";
            // if (i == c && j == item.size() - 1)
            // {
            //     cout << "out" << endl;
            //     break;
            // }
        }
        //  cout << endl;
    }
    // cout << "end" << endl;
    cout << arr[c][item.size() - 1];
}
