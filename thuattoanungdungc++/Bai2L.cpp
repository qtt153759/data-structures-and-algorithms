#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	do
	{
		cin >> n;
	} while (n < 3 || n > 100);
	int x;
	vector<int> vect;
	vector<int> vect1;
	vector<int> vect2;
	for (int i = 0; i < n; i++)
	{
		do
		{
			cin >> x;
		} while (x < -1000 || x > 1000 || typeid(x) != typeid(int));
		if (x < 0)
		{
			vect.push_back(x);
		}
		else if (x > 0)
		{
			vect1.push_back(x);
		}
		else if (x == 0)
		{
			vect2.push_back(x);
		}
	}
	if (vect.size() % 2 == 0)
	{
		x = vect.back();
		vect.pop_back();
		vect2.push_back(x);
	}
	if (vect1.size() == 0)
	{
		x = vect.back();
		vect1.push_back(x);
		vect.pop_back();
		x = vect.back();
		vect1.push_back(x);
		vect.pop_back();
	}
	cout << vect.size() << " ";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}
	cout << "\n"
		 << vect1.size() << " ";
	for (int i = 0; i < vect1.size(); i++)
	{
		cout << vect1[i] << " ";
	}

	cout << "\n"
		 << vect2.size() << " ";
	for (int i = 0; i < vect2.size(); i++)
	{
		cout << vect2[i] << " ";
	}
}
