#include<iostream>
#include <bits/stdc++.h>
using  namespace  std;

int  main() {
	unsigned long long a,b;
	do{
		cin>>a>>b;
	}while(a<1||b<1);
	unsigned long long e =pow(10,9)+7;
    unsigned long long c=a%e;
    unsigned long long d=b%e;
    c=(c+d)%e;
    cout<<c;
    //(a+b)%m=(((a%m)+(b%m))%m
}
