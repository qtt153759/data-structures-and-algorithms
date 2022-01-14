#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Solve(int n, long long arr[])
{
	stack<long> pstack; //stack luu vi tri l
	arr[n] = 0;
	long mark;
	long long area = 0;
	long long currentArea = 0;
	for (long i = 0; i <= n; i++)
	{
		mark = n + 10;
		//	cout << "xet " << arr[i] << endl;
		while (!pstack.empty() && arr[pstack.top()] > arr[i])
		{
			currentArea = arr[pstack.top()] * (pstack.empty() ? i : i - pstack.top());
			//		cout << "pop:" << pstack.top() << endl;
			pstack.pop();
			area = max(currentArea, area);
		}
		if (pstack.empty() || arr[pstack.top()] < arr[i])
		{

			pstack.push(i);
			//cout << "i -mark" << i << " " << mark << endl;
			//	cout << "push:" << pstack.top() << endl;
		}
	}
	return area;
}
int main()
{
	int n;
	cin >> n;
	do
	{
		long long arr[n + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << Solve(n, arr) << endl;
		cin >> n;
	} while (n != 0);
}
