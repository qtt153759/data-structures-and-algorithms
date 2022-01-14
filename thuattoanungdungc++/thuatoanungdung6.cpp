#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	long n;
	long e=pow(10,9)+7;
	do{
		cin>>n;
	}while(n>pow(10,6)&&n<=0);
	unsigned long sum=0;
	unsigned long x;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x<=pow(10,9)&&x>=0){
			sum=sum+x;
			sum=sum%e;
		}
	}

	printf("%lu",sum);
}
