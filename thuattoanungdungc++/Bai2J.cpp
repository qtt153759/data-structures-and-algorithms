#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
void pwd(vector<string> s)
{
    printf("/");
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
        cout << '/';
    }
    printf("\n");
}
int main()
{
    int n;
    do
    {
        cin >> n;
        getchar();
    } while (n < 1 || n > 50);
    string command;
    string str[n];
    vector<string> s;
    char delim = '/';
    string store;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "pwd")
        {
            pwd(s);
        }
        else
        {
            cin >> str[i];
            stringstream ss(str[i]);
            while (getline(ss, store, delim))
            {
                //cout << store << endl;
                if (store == "..")
                {
                    s.pop_back();
                }
                else if (store == "")
                {
                    s.clear();
                }
                else
                {
                    s.push_back(store);
                }
            }
        }
    }
}
