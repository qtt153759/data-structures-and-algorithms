#include<iostream>
#include<bits/stdc++.h>
using namespace std;
	string sline;
bool check(){
	getline(cin,sline);
		vector<char>vect;
		for(int j=0;j<sline.length();j++){
			if(sline[j]=='('||sline[j]=='['||sline[j]=='{'){
				vect.push_back(sline[j]);
			//	printf("push :%c",sline[j]);
			}
			else{
				
				char c=vect.back();
				vect.pop_back();
			//	printf("pop :%c",c);
				if(c=='('&&sline[j]!=')'){
				//	printf("\nsai ()");
					return false;
				}
				else if(c=='['&&sline[j]!=']'){
				//	printf("\nsai []");
					return false;
				}
				else if(c=='{'&&sline[j]!='}'){
				//	printf("\nsai {}");
					return false;
				}
			}
		}
		if(!vect.empty()){
			//printf("\n notempty\n");
			return false;
		}
		return true;
	}

int main(){
	int n;
	do{
		cin>>n;
		getchar();
	}while(n<0&&n>100);

	for(int i=0;i<n;i++){
		if(check()){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
   }
}
