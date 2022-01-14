#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	int res[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> s;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.empty() || arr[i] < arr[s[0]])
		{
			s.push_back(i);
			sort(s.begin(), s.end());
			res[i] = -1;
			cout << "push:" << i << " voi arr= " << arr[i] << endl;
		}
		else if (!s.empty() && arr[i] >= arr[s[0]])
		{
			cout << i << ":" << arr[i] << endl;
			// 	int l=0;
			// 	int r=s.size()-1;
			// //	printf("\n%d-%d-%d",l,r,arr[i]);
			// 	while(l<r-1){
			// 		int mid=(l+r)/2;
			// //		printf("--mid=%d   ",mid);
			// 		if(arr[i]<=arr[s[mid]]){
			// 			r=mid;
			// 		}else if(arr[i]>arr[s[mid]]){
			// 		    l=mid;
			// 		}
			// 	}

			//	res[i]=s[s.size()-1-l]-i-1;
			//		printf("\nres[%d]=%d voi s[%d]=%d",i,res[i],l,s[l]);
			cout << "s co:";
			for (vector<int>::iterator ptr = s.begin(); ptr < s.end(); ptr++)
			{
				cout << *ptr << " ";
			}
			cout << endl;
			vector<int>::iterator low = lower_bound(s.begin(), s.end(), arr[i]);
			cout << "ptr=" << *(--low) << " begin,end=" << *s.begin() << "-" << *s.end() << endl;
			res[i] = s[*low] - i - 1;
			cout << i << " co res :" << res[i] << endl;
		}
	}
	//	printf("\n");
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
}
