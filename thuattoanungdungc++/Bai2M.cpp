#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	stack<char>s;
	for(int i=0;i<str.length();i++){
		if(s.empty()||s.top() != str[i]){
			s.push(str[i]);
		}
		else{
			s.pop();
		}
	}
	if(s.empty()){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
