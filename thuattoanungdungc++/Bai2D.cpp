#include <bits/stdc++.h>
using namespace std;
int check[1000][1000];
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	queue<pair<int, int>> Q;
	check[0][0] = 1;
	Q.push({0, 0});
	while (!Q.empty())
	{
		int va = Q.front().first;
		int vb = Q.front().second;
		Q.pop();
		if (va == c || vb == c)
		{
			cout << check[va][vb] - 1;
			break;
		}
		if (check[va][b] == 0 && vb != b)
		{
			Q.push({va, b});
			check[va][b] = check[va][vb] + 1;
		}
		if (check[a][vb] == 0 && va != a)
		{
			Q.push({a, vb});
			check[a][vb] = check[va][vb] + 1;
		}
		if (va + vb <= b && check[0][va + vb] == 0)
		{
			Q.push({0, va + vb});
			check[0][va + vb] = check[va][vb] + 1;
		}
		else if (va + vb > b && check[va + vb - b][b] == 0)
		{
			Q.push({va + vb - b, b});
			check[va + vb - b][b] = check[va][vb] + 1;
		}
		if (va + vb <= a && check[va + vb][0] == 0)
		{
			Q.push({va + vb, 0});
			check[va + vb][0] = check[va][vb] + 1;
		}
		else if (va + vb > a && check[a][va + vb - a] == 0)
		{
			Q.push({a, va + vb - a});
			check[a][va + vb - a] = check[va][vb] + 1;
		}
		if (check[va][0] == 0 && vb != 0)
		{
			Q.push({va, 0});
			check[va][0] = check[va][vb] + 1;
		}
		if (check[0][vb] == 0 && va != 0)
		{
			Q.push({0, vb});
			check[0][vb] = check[va][vb] + 1;
		}
	}
}
