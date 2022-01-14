#include<iostream>
#include <bits/stdc++.h>
using  namespace  std;
string  sKey [12] = {
"",      "abc", "def",
"ghi",   "jkl", "mno",
"pqrs", "tuv", "wxyz",
"",      " ",    ""
};
int  main() {

    int T; cin  >>T;
    getchar();
    for (int t = 0; t < T; t++) {
    	string  sLine;
		getline(cin , sLine);
		int  res = 0;
		for (int i = 0; i < sLine.size (); i++) {
		    int  cur=0;
		    for (int j = 0; j < 12; j++) {
		        for (int k = 0; k < sKey[j].size (); k++) {
		            if (sLine[i] == sKey[j][k]) {
					    cur = k + 1;
		            }
		        }
		    }
	     	res += cur;
		}
		
		cout <<"Case #"<<t + 1<<": "<<res<<endl;
		
		
    }
    return  0;
    //luwu y laf sau khi cin int n thif phair getchar();
}
