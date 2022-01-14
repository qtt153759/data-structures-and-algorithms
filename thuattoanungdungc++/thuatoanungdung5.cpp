#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long a,b;
	unsigned long long e=pow(10,9)+7;
	do{
		cin>>a>>b;
	}while(a<1||b<1);
	a=a%e;
	b=b%(e-1);
	unsigned long long result=1;
	while(b>0){
		if(b%2>0){
			result=(result*a)%e;
		}
		a=(a*a)%e;
		b=b/2;
	}
	cout<<result;
	//(a^b)%m
	//buoc1: rut gon a=a%m;
	//buoc2:rut gon b=b%(m-1);
	//buoc3: neu b van lon thi phari phaan tisch thafnh soo nhij phaan sau ddos dang a^b=a^(2^i)*a^(2^i+1)*....
	//cachs phaan ticsh b thanh nhi phana co laf cuw layas b/2 dan dan toi khoong, rooif docdj nguowcj laji phaan soo duw

}
