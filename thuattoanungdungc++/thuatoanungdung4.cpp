#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int iArray[n];
	for(int i=0;i<n;i++){
		cin>>iArray[i];
	}
	int iValue[n];
	int sum=iArray[0];
	iValue[0]=sum;
	for(int i=1;i<n;i++){
		if(sum>=0){
			iValue[i]=sum+iArray[i];
		}else{
			iValue[i]=iArray[i];
		}
		sum=iValue[i];
	}
	cout<<*max_element(iValue,iValue+n);
	//*max_element(arr,arr+n)=>tim max trong arr[n]
}
