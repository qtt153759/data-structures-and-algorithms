#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string sline;
int k = 0;
void check()
{
    getline(cin, sline);
    vector<char> vect;
    deque<char> vect1;
    vector<char> vect2;
    for (int j = 0; j < sline.length(); j++)
    {
        //cout << "Xet " << sline[j] << endl;
        if (sline[j] == '(' || sline[j] == '[' || sline[j] == '{')
        {
            vect.push_back(sline[j]);
            //  printf("push vao vect :%c", sline[j]);
        }
        else
        {

            char c = vect.back();
            //  printf("cuoicung :%c", c);
            if (c == '(' && sline[j] == ')')
            {
                //	printf("\nsai ()");
                vect.pop_back();
                vect1.push_front('(');
                vect1.push_back(')');
                //     cout << "push cap()" << endl;
            }
            else if (c == '[' && sline[j] == ']')
            {
                vect.pop_back();
                vect1.push_front('[');
                vect1.push_back(']');
                //  cout << "push cap[]" << endl;
                k++;
            }
            else if (c == '{' && sline[j] == '}')
            {
                vect.pop_back();
                vect1.push_front('{');
                vect1.push_back('}');
                //  cout << "push cap{}" << endl;
            }
            else
            {

                for (int i = 0; i < vect1.size(); i++)
                {
                    vect2.push_back(vect1[i]);
                }
                vect.clear();
                vect1.clear();
                cout << "check" << endl;
                for (int i = 0; i < vect2.size(); i++)
                {
                    cout << vect2[i];
                }
            }
        }
    }
    cout << k << endl;
    for (int i = 0; i < vect2.size(); i++)
    {
        cout << vect2[i];
    }
}

int main()
{
    check();
}
