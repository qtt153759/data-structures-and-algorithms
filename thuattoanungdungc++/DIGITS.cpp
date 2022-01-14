#include <bits/stdc++.h>
using namespace std;
int n;
int arr[7]; //I,C,T,H,U,S,K
bool visited[10];
int current;
int digits = 0;
void Try(int k)
{

    for (int i = 1; i <= 9; i++)
    {
        if (!visited[i])
        {
            arr[k] = i;
            visited[i] = true;
            if (k == 6)
            {
                current = (arr[0] * 100 + arr[1] * 10 + arr[2]) - (arr[6] * 100 + 62) + (arr[3] * 1000 + arr[4] * 100 + arr[5] * 10 + arr[2]); //ICT−K62+HUST
                if (current == n)
                {
                    digits++;
                }
            }
            else
            {
                Try(k + 1);
            }
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    Try(0);
    cout << digits;
}