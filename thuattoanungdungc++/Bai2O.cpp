#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y;
    node(int a, int b)
    {
        x = a;
        y = b;
    }
};
int main()
{
    vector<node> s;
    int n;
    do
    {
        cin >> n;
    } while (n < 0 || n > 100);
    int a, b;
    s.push_back(node(-1,-1));
    for (int i = 1; i < n+1; i++)
    {
        cin >> a >> b;
        s.push_back(node(a, b));
    }

    vector<int> res;
    res.push_back(-1);
    int k = 1;
    while (k < n+1)
    {
    
        if (s[k].x == 0)
        {
            res.push_back(k);
            k++;
            break;
        }
        k++;
    }
    int i = 1;

    while (i < n+1)
    {  
        if (s[res[i]].y == 0)
        {
 
            while (k < n+1)
            {  
                if (s[k].x == 0)
                {
 
                    s[k].x = res[i];
                    s[res[i]].y = k;
                    res.push_back(k);

                    k++;
                    break;
                }
                k++;
            }
        }
        else
        { 
            res.push_back(s[res[i]].y);

        }
        i++;
    }
    for (int i = 1; i < n+1; i++)
    {
        cout << s[i].x << " " << s[i].y << endl;
    }
}
